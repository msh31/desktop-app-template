/*
 *  Also stolen from SaveManager ->
 * https://git.marco007.dev/marco/SaveManager/src/branch/main/src/frontend/ui/themes/themes.cpp
 */

#include "theme.hpp"

void ThemeManager::apply_style( ) {
    style = ImGui::GetStyle( );
    style.WindowPadding = { 12.f, 12.f };
    style.PopupRounding = 8.f;
    style.FramePadding = { 10.f, 6.f };
    style.ItemSpacing = { 10.f, 8.f };
    style.ItemInnerSpacing = { 8.f, 6.f };
    style.TouchExtraPadding = { 0.f, 0.f };
    style.IndentSpacing = 21.f;
    style.ScrollbarSize = 12.f;
    style.GrabMinSize = 12.f;
    style.WindowBorderSize = 0.f;
    style.ChildBorderSize = 1.f;
    style.PopupBorderSize = 1.f;
    style.FrameBorderSize = 1.f;
    style.TabBorderSize = 0.f;
    style.WindowRounding = 8.f;
    style.ChildRounding = 8.f;
    style.FrameRounding = 6.f;
    style.ScrollbarRounding = 8.f;
    style.GrabRounding = 12.f;
    style.TabRounding = 8.f;
    style.WindowTitleAlign = { 0.5f, 0.5f };
    style.ButtonTextAlign = { 0.5f, 0.5f };
    style.DisplaySafeAreaPadding = { 3.f, 3.f };

    ImGui::GetStyle( ) = style;
}

void ThemeManager::apply_scale( float scale ) {
    ImGuiStyle scaled = style;
    scaled.ScaleAllSizes( scale );
    ImGui::GetStyle( ) = scaled;
}

void ThemeManager::apply_colors( ThemeType theme ) {
    ThemeType selectedTheme = theme;

    auto& colors = ImGui::GetStyle( ).Colors;
    switch ( selectedTheme ) {
    case ThemeType::Dark:
        // Modern low-contrast slate surfaces with an indigo accent.
        colors[ImGuiCol_Text] = ImVec4( 0.93f, 0.93f, 0.95f, 1.00f );
        colors[ImGuiCol_TextDisabled] = ImVec4( 0.45f, 0.45f, 0.50f, 1.00f );
        colors[ImGuiCol_WindowBg] = ImVec4( 0.06f, 0.06f, 0.08f, 1.00f );
        colors[ImGuiCol_ChildBg] = ImVec4( 0.08f, 0.08f, 0.10f, 1.00f );
        colors[ImGuiCol_PopupBg] = ImVec4( 0.09f, 0.09f, 0.11f, 0.97f );
        colors[ImGuiCol_Border] = ImVec4( 0.20f, 0.20f, 0.24f, 0.50f );
        colors[ImGuiCol_BorderShadow] = ImVec4( 0.00f, 0.00f, 0.00f, 0.00f );
        colors[ImGuiCol_FrameBg] = ImVec4( 0.12f, 0.12f, 0.15f, 1.00f );
        colors[ImGuiCol_FrameBgHovered] = ImVec4( 0.16f, 0.16f, 0.20f, 1.00f );
        colors[ImGuiCol_FrameBgActive] = ImVec4( 0.20f, 0.20f, 0.24f, 1.00f );
        colors[ImGuiCol_TitleBg] = ImVec4( 0.06f, 0.06f, 0.08f, 1.00f );
        colors[ImGuiCol_TitleBgActive] = ImVec4( 0.09f, 0.09f, 0.11f, 1.00f );
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4( 0.00f, 0.00f, 0.00f, 0.51f );
        colors[ImGuiCol_MenuBarBg] = ImVec4( 0.06f, 0.06f, 0.08f, 1.00f );
        colors[ImGuiCol_ScrollbarBg] = ImVec4( 0.06f, 0.06f, 0.08f, 0.00f );
        colors[ImGuiCol_ScrollbarGrab] = ImVec4( 0.22f, 0.22f, 0.26f, 1.00f );
        colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.28f, 0.28f, 0.33f, 1.00f );
        colors[ImGuiCol_ScrollbarGrabActive] = ImVec4( 0.34f, 0.34f, 0.40f, 1.00f );
        colors[ImGuiCol_CheckMark] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_SliderGrab] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_SliderGrabActive] = ImVec4( 0.51f, 0.55f, 0.97f, 1.00f );
        colors[ImGuiCol_Button] = ImVec4( 0.13f, 0.13f, 0.16f, 1.00f );
        colors[ImGuiCol_ButtonHovered] = ImVec4( 0.18f, 0.18f, 0.22f, 1.00f );
        colors[ImGuiCol_ButtonActive] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_Header] = ImVec4( 0.39f, 0.40f, 0.95f, 0.35f );
        colors[ImGuiCol_HeaderHovered] = ImVec4( 0.39f, 0.40f, 0.95f, 0.20f );
        colors[ImGuiCol_HeaderActive] = ImVec4( 0.39f, 0.40f, 0.95f, 0.45f );
        colors[ImGuiCol_Separator] = ImVec4( 0.20f, 0.20f, 0.24f, 0.50f );
        colors[ImGuiCol_SeparatorHovered] = ImVec4( 0.51f, 0.55f, 0.97f, 0.50f );
        colors[ImGuiCol_SeparatorActive] = ImVec4( 0.51f, 0.55f, 0.97f, 0.80f );
        colors[ImGuiCol_ResizeGrip] = ImVec4( 0.39f, 0.40f, 0.95f, 0.20f );
        colors[ImGuiCol_ResizeGripHovered] = ImVec4( 0.39f, 0.40f, 0.95f, 0.40f );
        colors[ImGuiCol_ResizeGripActive] = ImVec4( 0.39f, 0.40f, 0.95f, 0.60f );
        colors[ImGuiCol_Tab] = ImVec4( 0.09f, 0.09f, 0.11f, 1.00f );
        colors[ImGuiCol_TabHovered] = ImVec4( 0.16f, 0.16f, 0.20f, 1.00f );
        colors[ImGuiCol_TabActive] = ImVec4( 0.13f, 0.13f, 0.16f, 1.00f );
        colors[ImGuiCol_TabUnfocused] = ImVec4( 0.06f, 0.06f, 0.08f, 1.00f );
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4( 0.09f, 0.09f, 0.11f, 1.00f );
        colors[ImGuiCol_TabSelectedOverline] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_PlotLines] = ImVec4( 0.55f, 0.55f, 0.60f, 1.00f );
        colors[ImGuiCol_PlotLinesHovered] = ImVec4( 0.51f, 0.55f, 0.97f, 1.00f );
        colors[ImGuiCol_PlotHistogram] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_PlotHistogramHovered] = ImVec4( 0.51f, 0.55f, 0.97f, 1.00f );
        colors[ImGuiCol_TextSelectedBg] = ImVec4( 0.39f, 0.40f, 0.95f, 0.35f );
        colors[ImGuiCol_DragDropTarget] = ImVec4( 0.39f, 0.40f, 0.95f, 0.90f );
        colors[ImGuiCol_NavHighlight] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_NavWindowingHighlight] = ImVec4( 1.00f, 1.00f, 1.00f, 0.70f );
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4( 0.70f, 0.70f, 0.75f, 0.20f );
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4( 0.05f, 0.05f, 0.07f, 0.50f );
        break;
    case ThemeType::Light:
        // Same indigo accent, deepened for contrast against light surfaces.
        colors[ImGuiCol_Text] = ImVec4( 0.12f, 0.13f, 0.16f, 1.00f );
        colors[ImGuiCol_TextDisabled] = ImVec4( 0.55f, 0.55f, 0.60f, 1.00f );
        colors[ImGuiCol_WindowBg] = ImVec4( 0.98f, 0.98f, 0.99f, 1.00f );
        colors[ImGuiCol_ChildBg] = ImVec4( 0.95f, 0.95f, 0.97f, 1.00f );
        colors[ImGuiCol_PopupBg] = ImVec4( 0.99f, 0.99f, 1.00f, 0.98f );
        colors[ImGuiCol_Border] = ImVec4( 0.85f, 0.85f, 0.88f, 0.80f );
        colors[ImGuiCol_BorderShadow] = ImVec4( 0.00f, 0.00f, 0.00f, 0.00f );
        colors[ImGuiCol_FrameBg] = ImVec4( 0.94f, 0.94f, 0.96f, 1.00f );
        colors[ImGuiCol_FrameBgHovered] = ImVec4( 0.90f, 0.90f, 0.93f, 1.00f );
        colors[ImGuiCol_FrameBgActive] = ImVec4( 0.86f, 0.86f, 0.90f, 1.00f );
        colors[ImGuiCol_TitleBg] = ImVec4( 0.95f, 0.95f, 0.97f, 1.00f );
        colors[ImGuiCol_TitleBgActive] = ImVec4( 0.92f, 0.92f, 0.95f, 1.00f );
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4( 0.90f, 0.90f, 0.90f, 0.51f );
        colors[ImGuiCol_MenuBarBg] = ImVec4( 0.98f, 0.98f, 0.99f, 1.00f );
        colors[ImGuiCol_ScrollbarBg] = ImVec4( 0.98f, 0.98f, 0.99f, 0.00f );
        colors[ImGuiCol_ScrollbarGrab] = ImVec4( 0.82f, 0.82f, 0.86f, 1.00f );
        colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.72f, 0.72f, 0.78f, 1.00f );
        colors[ImGuiCol_ScrollbarGrabActive] = ImVec4( 0.62f, 0.62f, 0.70f, 1.00f );
        colors[ImGuiCol_CheckMark] = ImVec4( 0.31f, 0.27f, 0.90f, 1.00f );
        colors[ImGuiCol_SliderGrab] = ImVec4( 0.31f, 0.27f, 0.90f, 1.00f );
        colors[ImGuiCol_SliderGrabActive] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_Button] = ImVec4( 0.93f, 0.93f, 0.96f, 1.00f );
        colors[ImGuiCol_ButtonHovered] = ImVec4( 0.88f, 0.88f, 0.92f, 1.00f );
        colors[ImGuiCol_ButtonActive] = ImVec4( 0.31f, 0.27f, 0.90f, 1.00f );
        colors[ImGuiCol_Header] = ImVec4( 0.31f, 0.27f, 0.90f, 0.15f );
        colors[ImGuiCol_HeaderHovered] = ImVec4( 0.31f, 0.27f, 0.90f, 0.10f );
        colors[ImGuiCol_HeaderActive] = ImVec4( 0.31f, 0.27f, 0.90f, 0.25f );
        colors[ImGuiCol_Separator] = ImVec4( 0.85f, 0.85f, 0.88f, 0.80f );
        colors[ImGuiCol_SeparatorHovered] = ImVec4( 0.31f, 0.27f, 0.90f, 0.50f );
        colors[ImGuiCol_SeparatorActive] = ImVec4( 0.31f, 0.27f, 0.90f, 0.80f );
        colors[ImGuiCol_ResizeGrip] = ImVec4( 0.31f, 0.27f, 0.90f, 0.20f );
        colors[ImGuiCol_ResizeGripHovered] = ImVec4( 0.31f, 0.27f, 0.90f, 0.40f );
        colors[ImGuiCol_ResizeGripActive] = ImVec4( 0.31f, 0.27f, 0.90f, 0.60f );
        colors[ImGuiCol_Tab] = ImVec4( 0.93f, 0.93f, 0.96f, 1.00f );
        colors[ImGuiCol_TabHovered] = ImVec4( 0.88f, 0.88f, 0.92f, 1.00f );
        colors[ImGuiCol_TabActive] = ImVec4( 0.99f, 0.99f, 1.00f, 1.00f );
        colors[ImGuiCol_TabUnfocused] = ImVec4( 0.95f, 0.95f, 0.97f, 1.00f );
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4( 0.93f, 0.93f, 0.96f, 1.00f );
        colors[ImGuiCol_TabSelectedOverline] = ImVec4( 0.31f, 0.27f, 0.90f, 1.00f );
        colors[ImGuiCol_PlotLines] = ImVec4( 0.50f, 0.50f, 0.55f, 1.00f );
        colors[ImGuiCol_PlotLinesHovered] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_PlotHistogram] = ImVec4( 0.31f, 0.27f, 0.90f, 1.00f );
        colors[ImGuiCol_PlotHistogramHovered] = ImVec4( 0.39f, 0.40f, 0.95f, 1.00f );
        colors[ImGuiCol_TextSelectedBg] = ImVec4( 0.31f, 0.27f, 0.90f, 0.25f );
        colors[ImGuiCol_DragDropTarget] = ImVec4( 0.31f, 0.27f, 0.90f, 0.90f );
        colors[ImGuiCol_NavHighlight] = ImVec4( 0.31f, 0.27f, 0.90f, 1.00f );
        colors[ImGuiCol_NavWindowingHighlight] = ImVec4( 0.15f, 0.15f, 0.18f, 0.70f );
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4( 0.50f, 0.50f, 0.55f, 0.20f );
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4( 0.50f, 0.50f, 0.55f, 0.35f );
        break;
    case ThemeType::Custom:
        // TODO: handle this, maybe open upp some customizer menu. future....
        break;
    }
}
