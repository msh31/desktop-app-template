#include "app.hpp"
#include <branding.hpp>
#include <logger.hpp>

#include <frontend/icons.hpp>
#include <frontend/theme/theme.hpp>

#include <frontend/views/cache_demo/cache_demo_view.hpp>
#include <frontend/views/debug/debug_view.hpp>
#include <frontend/views/home/home_view.hpp>
#include <frontend/views/pipeline/pipeline_demo.hpp>
#include <frontend/views/settings/settings_view.hpp>
#include <frontend/views/log/log_view.hpp>
#include <frontend/views/image_demo/image_demo_view.hpp>

#include <frontend/dialogs/confirm/confirm_dialog.hpp>
#include <frontend/notification/notification.hpp>

void CApp::init( ) {
    SPDLOG_INFO( "Setting up application views.." );
    m_ui_manager.add_view( { std::make_unique<CHomeView>( ), ICON_HOME, "Home" } );
    m_ui_manager.add_view( { std::make_unique<CPipelineView>( ), ICON_PIPE, "Pipeline Demo" } );
    m_ui_manager.add_view( { std::make_unique<CDebugView>( ), ICON_BUG, "Debug" } );
    m_ui_manager.add_view( { std::make_unique<CCacheDemoView>( ), ICON_CACHE, "Cache Demo" } );
    m_ui_manager.add_view( { std::make_unique<CImageDemoView>( ), ICON_IMAGE, "Image Demo" } );
    m_ui_manager.add_view( { std::make_unique<CLogView>( ), ICON_SCROLL, "Logs" } );
    m_ui_manager.set_settings_view( { std::make_unique<CSettingsView>( m_config ), ICON_GEAR, "Settings" } );

    //SPDLOG_INFO( "Setting up the menubar.." );
    //m_menubar.add_group(
    //    { "File",
    //      {
    //          { ICON_NEW_FILE, "New", [] { Notify::show_notification( "File", "New", 1500 ); } },
    //          { ICON_OPEN, "Open", [] { Notify::show_notification( "File", "Open", 1500 ); } },
    //          { ICON_SAVE, "Save", [] { Notify::show_notification( "File", "Saved!", 1500 ); } },
    //      } } );
    //m_menubar.add_group(
    //    { "Options",
    //      {
    //          { ICON_THEME, "Dark Mode", nullptr, &m_config.settings.dark_mode },
    //          { ICON_TEST, "Feature A", nullptr, &m_toggle_a },
    //          { ICON_TEST2, "Feature B", nullptr, &m_toggle_b },
    //          { ICON_TEST3, "Feature C", nullptr, &m_toggle_c },
    //          { ICON_TEST4, "Feature D", nullptr, &m_toggle_d },
    //          { ICON_TEST5, "Feature E", nullptr, &m_toggle_e },
    //      } } );
    //m_ui_manager.set_menubar( std::move( m_menubar ) );

    SPDLOG_INFO( "Setting up statusbar.." );
    m_statusbar.add_left( { "I am a statusbar", "X" } );
    m_statusbar.add_right( { "Build", APP_VERSION.data( ) } );
    m_ui_manager.set_statusbar( std::move( m_statusbar ) );
}

void CApp::render( ) {
    m_ui_manager.render( );

    // rendered on top of the general UI
    Notify::render_notifications( );
    ConfirmDialog::render( );
}
