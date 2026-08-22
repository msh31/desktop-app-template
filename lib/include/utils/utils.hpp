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

namespace utils { //All functions in this namespace should work across Windows, Linux and macOS
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

    // file_clock::to_sys / from_sys are not available on MSVC or Apple Clang
    static std::chrono::system_clock::time_point file_time_to_sys( fs::file_time_type ft ) {
        return std::chrono::system_clock::now( ) + std::chrono::duration_cast<std::chrono::system_clock::duration>(
                                                       ft - fs::file_time_type::clock::now( ) );
    }

    static fs::file_time_type sys_to_file_time( std::chrono::system_clock::time_point tp ) {
        return fs::file_time_type::clock::now( ) + std::chrono::duration_cast<fs::file_time_type::clock::duration>(
                                                       tp - std::chrono::system_clock::now( ) );
    }

    static std::string format_file_time( fs::file_time_type f ) {
#ifdef __APPLE__
        char buf[32];
        auto ts = std::chrono::system_clock::to_time_t( file_time_to_sys( f ) );
        auto tm = std::localtime( &ts );
        std::strftime( buf, sizeof( buf ), "%d-%m-%y %H:%M:%S", tm );
        return buf;
#else
        auto time = std::chrono::current_zone( )->to_local( file_time_to_sys( f ) );
        auto floored = std::chrono::floor<std::chrono::seconds>( time );
        return std::format( "{:%d-%m-%y %H:%M:%S}", floored );
#endif
    }

    static std::string format_file_size( uintmax_t size ) {
        constexpr uintmax_t KB = 1024, MB = KB * 1024, GB = MB * 1024;

        if ( size >= GB ) return std::format( "{:.2f}GB", static_cast<double>( size ) / GB );
        if ( size >= MB ) return std::format( "{:.2f}MB", static_cast<double>( size ) / MB );
        if ( size >= KB ) return std::format( "{:.2f}KB", static_cast<double>( size ) / KB );
        return std::format( "{}B", size );
    }
}