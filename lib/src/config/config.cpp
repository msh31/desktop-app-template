#include <config/config.hpp>
#include <logger.hpp>
#include <utils/utils.hpp>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

CConfig::CConfig( ) {
    try {
        if ( !fs::exists( paths::config_dir( ) ) ) {
            if ( !fs::create_directories( paths::config_dir( ) ) ) {
                throw std::runtime_error( "[Config] Failed to create config directory" );
            }
        }

        if ( !fs::exists( m_config_file ) ) {
            fs::create_directories( paths::backgrounds_dir( ) );
            fs::create_directories( paths::cache_dir( ) );

            m_load_ok = true; // initial creation
            save( );
        }

        m_load_ok = load( );
    } catch ( const std::exception& err ) {
        SPDLOG_CRITICAL( "[Config] constructor: {}", err.what( ) );
    }
}

CConfig::~CConfig( ) {
    try {
        SPDLOG_INFO( "[Config] saving before exiting.." );
        save( );
    } catch ( const std::exception& err ) {
        SPDLOG_CRITICAL( "[Config] destructor: {}", err.what( ) );
    }
}

CConfig& CConfig::get( ) {
    static CConfig instance;
    return instance;
}

bool CConfig::save( ) {
    if ( !m_load_ok ) {
        SPDLOG_ERROR( "[Config] failed to load!" );
        return false;
    }
    json data;
    data["dark_mode"] = settings.dark_mode;
    data["use_bg"] = settings.use_bg;
    data["bg_name"] = settings.bg_name;

    data["window_w"] = settings.window_w;
    data["window_h"] = settings.window_h;

    auto res = utils::atomic_write( m_config_file, data.dump( 4 ) );
    if ( !res ) {
        SPDLOG_ERROR( "[Config] failed to save!" );
        return false;
    }
    return true;
}

bool CConfig::load( ) {
    json data;

    std::ifstream file( m_config_file.c_str( ) );
    if ( !file.is_open( ) ) {
        SPDLOG_ERROR( "[Config] Failed to open!" );
        return false;
    }

    try {
        data = json::parse( file );
        if ( data.empty() ) return false;

        settings.dark_mode = data.value( "dark_mode", true );
        settings.use_bg = data.value( "use_bg", false );
        settings.bg_name = data.value( "bg_name", std::string( "" ) );

        settings.window_w = data.value( "window_w", 0 );
        settings.window_h = data.value( "window_h", 0 );
    } catch ( json::exception& ex ) {
        SPDLOG_CRITICAL( "[Config] parsing error: {}", ex.what( ) );
        m_was_reset = true;
        
        std::error_code ec;
        fs::rename( m_config_file, m_config_file.string( ) + ".bak", ec );
        if ( ec ) {
            SPDLOG_CRITICAL( "[Config] failed to backup config! this is bad..." );
            return false;
        }

        settings = { };
        return true;
    }
    return true;
}
