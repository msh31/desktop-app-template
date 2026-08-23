#include "cache_demo_view.hpp"
#include <utils/paths.hpp>

#include <frontend/childguard.hpp>
#include <frontend/components/spinner.hpp>

void CCacheDemoView::on_enter( ) {
    m_cache.refresh( [this] {
        std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
        return m_seed_data;
    } );
};

void CCacheDemoView::render( ) {
    auto mem_cache = m_cache.get( );
    auto dsk_cache = m_disk_cache.get( );

    {
        ChildGuard memcache("memcache", { 0.0f, 0.0f }, ImGuiChildFlags_Borders | ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_AutoResizeX );
        ImGui::Text( "Memory Cache Demo | Using a fake timer to simulate the work" );
        if ( m_cache.is_refreshing( ) ) {
            Spinner::render( );
        } else {
            for ( const auto& entry : mem_cache ) {
                ImGui::TextColored( ImColor( 49, 206, 234 ).Value, "Item Name: %s", entry.name.c_str( ) );
                ImGui::SameLine( );
                ImGui::TextColored( ImColor( 50, 185, 18 ).Value, "Price: %f", entry.floaty );
                ImGui::SameLine( );
                ImGui::Text( " History: " );
                ImGui::SameLine( );
                for ( const auto& n : entry.numbers ) {
                    ImGui::TextColored( ImColor( 100, 100, 100 ).Value, "$%d,", n );
                    ImGui::SameLine( );
                }
                ImGui::NewLine( );
            }
        }
    }

    ImGui::SameLine( );

    {
        ChildGuard dskcache( "dskcache", { 0.0f, 0.0f }, ImGuiChildFlags_Borders | ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_AutoResizeX );
        ImGui::Text( "Disk Cache Demo | Using a fake timer to simulate the work" );

        if ( m_disk_cache.is_refreshing( ) ) {
            Spinner::render( );
        } else {
            if ( ImGui::Button( "Refresh" ) ) {
                m_disk_cache.refresh( [this] {
                    std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
                    return m_seed_data;
                } );
            }

            for ( const auto& entry : dsk_cache ) {
                ImGui::TextColored( ImColor( 49, 206, 234 ).Value, "Item Name: %s", entry.name.c_str( ) );
                ImGui::SameLine( );
                ImGui::TextColored( ImColor( 50, 185, 18 ).Value, "Price: %f", entry.floaty );
                ImGui::SameLine( );
                ImGui::Text( " History: " );
                ImGui::SameLine( );
                for ( const auto& n : entry.numbers ) {
                    ImGui::TextColored( ImColor( 100, 100, 100 ).Value, "$%d,", n );
                    ImGui::SameLine( );
                }
                ImGui::NewLine( );
            }
        }
    }
    }

void CCacheDemoView::on_exit( ) {}
