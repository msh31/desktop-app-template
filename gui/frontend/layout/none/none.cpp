#include "none.hpp"

CBaseView* CNoShell::render( CBaseView* active ) {
    ImGui::BeginChild( "##content", { 0, 0 }, ImGuiChildFlags_Borders );
    if ( active ) active->render( );
    ImGui::EndChild( );

    return nullptr;
}
