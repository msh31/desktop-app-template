#include "settings_view.hpp"
#include <utils/utils.hpp>

#include <frontend/theme/theme.hpp>
#include <frontend/childguard.hpp>
#include <frontend/notification/notification.hpp>

CSettingsView::CSettingsView( CConfig& cfg ) : m_config( cfg ) {};

void CSettingsView::on_enter() {
    for ( const auto& f : fs::directory_iterator( paths::backgrounds_dir( ), fs::directory_options::skip_permission_denied ) ) {
        m_backgrounds.emplace_back( f.path( ).filename( ).string( ) );
    }

    for ( const auto& b : m_backgrounds ) {
        m_labels.push_back( b.c_str( ) );
    }
    auto it = std::find( m_backgrounds.begin( ), m_backgrounds.end( ), m_config.settings.bg_name );
    if ( it != m_backgrounds.end( ) ) {
        m_current_background = (int)std::distance( m_backgrounds.begin( ), it );
    }
}

void CSettingsView::render( ) {
    static bool test = false;

    {
        ChildGuard appearance( "Appearance", { 300.0f, 0.0f }, ImGuiChildFlags_Borders | ImGuiChildFlags_AutoResizeY );
        ImGui::Text( "Appearance" );

        if ( ImGui::Checkbox( "Dark Mode", &m_config.settings.dark_mode ) ) {
            ThemeManager::apply_colors( m_config.settings.dark_mode ? ThemeType::Dark : ThemeType::Light );
        }

        ImGui::Separator( );

        ImGui::Checkbox( "Use Shader", &test );

        const char* items[] = { "Apple", "Banana", "Cherry", "Kiwi", "Mango", "Orange", "Pineapple", "Strawberry", "Watermelon" };
        static int item_current = 1;
        ImGui::ListBox( "##shader_list", &item_current, items, IM_COUNTOF( items ), 4 );

        ImGui::Separator( );

        if ( (int)m_backgrounds.size( ) <= 0 ) {
            auto str = std::format( "No backgrounds found, add some here: {}", paths::backgrounds_dir( ).string( ) );
            ImGui::TextWrapped( "%s", str.c_str( ) );
        } else {
            ImGui::Checkbox( "Custom Background", &m_config.settings.use_bg );
            if ( ImGui::ListBox( "##bg_list", &m_current_background, m_labels.data( ), (int)m_labels.size( ), 4 ) ) {
                m_config.settings.bg_name = m_backgrounds[m_current_background];
            }
        }

        ImGui::Separator( );
    }

    ImGui::SameLine( );

    {
        ChildGuard config( "Configuration", { 150.0f, 0.0f }, ImGuiChildFlags_Borders | ImGuiChildFlags_AutoResizeY );
        ImGui::Text( "Configuration" );

        if ( ImGui::Button( "Open" ) ) {
            open_in_file_manager( paths::config_dir( ).string( ).c_str( ) );
        }
        ImGui::SetItemTooltip( "Opens your file manager to the config directory." );

        ImGui::SameLine( );
        if ( ImGui::Button( "Save" ) ) {
            m_config.save( );
            Notify::show_notification( "Config", "Saved config!", 1500 );
        }
    }
}

void CSettingsView::on_exit( ) {

}

CSettingsView::~CSettingsView( ) {}
