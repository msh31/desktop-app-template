#pragma once
#include <logger.hpp>

#ifdef __APPLE__
    #include <spawn.h>
    #include <sys/wait.h>
#endif
#ifdef __linux__
    #include <sys/wait.h>
#endif
#ifdef _WIN32
    #include <shellapi.h>
#endif

inline std::string get_username( ) {
#if defined( __linux__ ) || defined( __APPLE__ )
    return std::getenv( "USER" );
#else
    return std::getenv( "USERNAME" );
#endif
}

inline void open_in_file_manager( const char* path ) {
#ifdef __linux__
    pid_t pid = fork( );
    pid_t w = 0;
    int status;

    if ( pid > 0 ) {
        w = waitpid( pid, &status, 0 );
        if ( w == -1 ) {
            SPDLOG_ERROR( "waitpid failed: {}", strerror( errno ) );
        }
    }

    if ( pid == 0 ) {
        pid_t g_pid = fork( );

        if ( g_pid == 0 ) {
            execl( "/usr/bin/xdg-open", "xdg-open", path, nullptr );
            _exit( 1 );
        }
        _exit( 0 );
    }
#endif
#ifdef _WIN32
    ShellExecuteA( NULL, "open", path, NULL, NULL, SW_SHOWDEFAULT );
#endif
#ifdef __APPLE__
    extern char** environ;
    pid_t pid;

    const char* argv[] = { "open", path, nullptr };
    int status = posix_spawn( &pid, "/usr/bin/open", nullptr, nullptr, (char* const*)argv, environ );
    if ( status == 0 ) {
        waitpid( pid, &status, 0 );
    }
#endif
}
