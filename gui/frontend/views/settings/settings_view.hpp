#pragma once
#include <frontend/views/base_view.hpp>

class CSettingsView : public CBaseView {
    public:
        CSettingsView( CConfig& cfg );
        ~CSettingsView( ) override;
        void render( ) override;

    private:
        CConfig& m_config;
};
