#pragma once
#include <frontend/views/base_view.hpp>

class CSettingsView : public CBaseView {
    public:
        ~CSettingsView( ) override;
        void render( ) override;
        void on_enter( ) override;
        void on_exit( ) override;

    private:
        std::vector<std::string> m_backgrounds = { };
        int m_current_background = 0;

        float m_font_scale = 1.0f;
        float m_font_scale_min = 0.80f;
        float m_font_scale_max = 1.50f;
};
