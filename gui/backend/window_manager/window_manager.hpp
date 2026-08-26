#pragma once
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <backend/font_manager/font_manager.hpp>
#include <config/config.hpp>

class CWindowManager {
    public:
        explicit CWindowManager( CConfig& config ) : m_config( config ) {
            setup_opengl( );
            setup_imgui( );
        }
        ~CWindowManager( ) {
            if ( m_window != nullptr ) {
                ImGui_ImplOpenGL3_Shutdown( );
                ImGui_ImplGlfw_Shutdown( );
                ImGui::DestroyContext( );
                glfwDestroyWindow( m_window );
                glfwTerminate( );
            }
        }

        void run( std::function<void( )> fun );

    private:
        CConfig& m_config;
        GLFWwindow* m_window = nullptr;
        float m_content_scale = 1.0f;
        std::function<void( )> m_render_fn;

        void setup_opengl( );
        void setup_imgui( );
        void apply_content_scale( float scale );
        bool should_continue( );
        void remember_window_size( );
        void render_frame( );
};
