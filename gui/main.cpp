#include <backend/app.hpp>
#include <logger.hpp>
#include <backend/window_manager/window_manager.hpp>

#ifdef _WIN32 // forces Windows to treat the app as a GUI Application
    #pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
#endif

int main( ) {
    try {
        setup_logger( );
        SPDLOG_INFO( "==============={}===============", APP_NAME.data( ) );
        CConfig config;
        CWindowManager window( config );
        CApp app( config );

        app.init( );
        SPDLOG_INFO( "Initialized succesfully!" );
        window.run( [&app] { app.render( ); } );
    } catch ( const std::exception& e ) {
        SPDLOG_CRITICAL( "Fatal: {}", e.what( ) );
        return 1;
    }
    return 0;
}
