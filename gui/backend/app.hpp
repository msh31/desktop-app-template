#pragma once
#include <config/config.hpp>
#include <utils/paths.hpp>
#include <backend/ui_manager/ui_manager.hpp>
#include <backend/image_manager/image_manager.hpp>

 #include <frontend/layout/tabbar/tabbar.hpp>
//#include <frontend/layout/sidebar/sidebar.hpp>
// #include <frontend/layout/ribbon/ribbon.hpp>
// #include <frontend/layout/none/none.hpp>

class CApp {
    public:
        explicit CApp( CConfig& config ) : m_config( config ) {}

        void init( );
        void render( );

    private:
        void refresh_background( );

        CConfig& m_config;
         CUIManager m_ui_manager { std::make_unique<CTabbarShell>() };
        //CUIManager m_ui_manager{ std::make_unique<CSidebarShell>( ) };
        // CUIManager m_ui_manager{ std::make_unique<CNoShell>( ) }; // kinda sucks
        // CUIManager m_ui_manager { std::make_unique<CRibbonShell>() };

        bool m_toggle_a = false, m_toggle_b = false, m_toggle_c = true, m_toggle_d = false, m_toggle_e = false;

        CMenuBar m_menubar;
        CStatusBar m_statusbar;

        ImageData m_background_image = { };
        std::string m_loaded_bg_name = { };
};
