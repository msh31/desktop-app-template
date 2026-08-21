#pragma once
#include <branding.hpp>

namespace fs = std::filesystem;

namespace paths {
    inline fs::path g_config_dir;
    inline void set_config_dir( const fs::path& p ) { g_config_dir = p; }

    inline fs::path home_dir( ) {
        const char* home;
#if defined( __linux__ ) || defined( __APPLE__ )
        home = std::getenv( "HOME" );
#elif defined( _WIN32 )
        home = std::getenv( "USERPROFILE" );
#endif
        if ( !home ) throw std::runtime_error( "HOME not set, how did you manage to do this?" );
        return fs::path( home );
    }

    inline fs::path default_config_dir( ) {
#if defined( __linux__ )
        return home_dir( ) / ".config" / APP_NAME.data( );
#elif defined( __APPLE__ )
        return home_dir( ) / "Library" / "Application Support" / APP_NAME.data( );
#elif defined( _WIN32 )
        return home_dir( ) / "AppData" / "Roaming" / APP_NAME.data( );
#endif
    }

    inline fs::path config_dir( ) {
        if ( !g_config_dir.empty( ) ) {
            return g_config_dir;
        }

        return default_config_dir( );
    }

    inline fs::path redirect_file( ) { return config_dir( ) / "cfg.redirect"; }
    inline fs::path log_dir( ) { return config_dir( ) / "logs"; }
    inline fs::path cache_dir( ) { return config_dir( ) / "cache"; }

#if defined( _WIN32 )
    inline fs::path documents_dir( ) {
        PWSTR path = NULL;
        HRESULT h_res = SHGetKnownFolderPath( FOLDERID_Documents, 0, NULL, &path );
        if ( SUCCEEDED( h_res ) ) {
            fs::path result( path );
            CoTaskMemFree( path );
            return result;
        } else {
            throw std::runtime_error( "USERPROFILE not set, how did you manage to do this?" );
        }
    }
#endif

    inline fs::path log_file( ) { return log_dir( ) / std::format( "{}.log", APP_NAME.data( ) ); }
}; // namespace paths
