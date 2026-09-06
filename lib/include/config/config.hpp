#pragma once
#include <utils/paths.hpp>

class CConfig {
    public:
        CConfig( );
        ~CConfig( );

        static CConfig& get( );

        bool save( );

        struct AppConfig {
                bool dark_mode = true;
                bool use_bg = false;
                std::string bg_name = { };

                // 0 means "unset" - window_manager computes a default from the primary monitor
                int window_w = 0;
                int window_h = 0;
        };

        AppConfig settings;

        // delete copy & move constructors since there must only be 1 instance
        CConfig( const CConfig& ) = delete;
        CConfig& operator=( const CConfig& ) = delete;
        CConfig( CConfig&& ) = delete;
        CConfig& operator=( CConfig&& ) = delete;

    private:
        fs::path m_config_file = paths::config_dir( ) / "config.json";

        bool load( );
        bool m_load_ok = false;
};
