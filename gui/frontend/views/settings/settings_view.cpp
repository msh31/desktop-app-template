#include "settings_view.hpp"
#include <utils/utils.hpp>

CSettingsView::CSettingsView( CConfig& cfg ) : m_config( cfg ) {};

void CSettingsView::on_enter( ) {}

void CSettingsView::render( ) {
    ImGui::Checkbox( "Dark Mode", &m_config.settings.dark_mode );

    if ( ImGui::Button( "Open config" ) ) {
        open_in_file_manager( paths::config_dir( ).string( ).c_str( ) );
    }
    ImGui::SetItemTooltip( "Opens your file manager to the config directory." );
}

void CSettingsView::on_exit( ) {}

CSettingsView::~CSettingsView( ) {}
