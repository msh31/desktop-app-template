#include "settings_view.hpp"
#include <utils/utils.hpp>

#include <frontend/theme/theme.hpp>
#include <frontend/childguard.hpp>
#include <frontend/notification/notification.hpp>

CSettingsView::CSettingsView( CConfig& cfg ) : m_config( cfg ) {};

void CSettingsView::on_enter( ) {}

void CSettingsView::render( ) {
    static bool test = false, test2 = false;

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

        ImGui::Checkbox( "Custom Background", &test2 );

        const char* bg_items[] = { "Apple", "Banana", "Cherry", "Kiwi", "Mango", "Orange", "Pineapple", "Strawberry", "Watermelon" };
        static int bg_item_current = 0;
        ImGui::ListBox( "##bg_list", &bg_item_current, bg_items, IM_COUNTOF( bg_items ), 4 );
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

void CSettingsView::on_exit( ) {}

CSettingsView::~CSettingsView( ) {}
