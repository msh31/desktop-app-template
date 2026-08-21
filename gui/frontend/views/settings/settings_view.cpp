#include "settings_view.hpp"
#include <utils/utils.hpp>
#include <frontend/theme/theme.hpp>

CSettingsView::CSettingsView( CConfig& cfg ) : m_config( cfg ) {};

void CSettingsView::on_enter( ) {}

void CSettingsView::render( ) {
    if ( ImGui::Checkbox( "Dark Mode", &m_config.settings.dark_mode ) ) {
        ThemeManager::apply_colors( m_config.settings.dark_mode ? ThemeType::Dark : ThemeType::Light );
    }

    if ( ImGui::Button( "Open config" ) ) {
        open_in_file_manager( paths::config_dir( ).string( ).c_str( ) );
    }
    ImGui::SetItemTooltip( "Opens your file manager to the config directory." );
}

void CSettingsView::on_exit( ) {}

CSettingsView::~CSettingsView( ) {}
