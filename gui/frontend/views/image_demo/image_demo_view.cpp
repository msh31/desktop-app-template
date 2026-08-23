#include "image_demo_view.hpp"
#include <logger.hpp>

#include <frontend/childguard.hpp>
#include <frontend/images/pepe.hpp>

void CImageDemoView::on_enter( ) { 
	m_embedded = CImageManager::get( ).load_from_memory( pepe_png, pepe_png_len, "pepe" );
};

void CImageDemoView::render( ) { 
    ImGui::Text( "Hello, this is the image demo view" );

    auto avail = ImGui::GetContentRegionAvail( );
    auto scale = std::min( avail.x / m_embedded.texture_width, avail.y / m_embedded.texture_height );

	{
        ChildGuard pepe( "pepe", { 0.0f, 0.0f } );

        ImGui::Image((ImTextureID)m_embedded.texture_id, ImVec2( m_embedded.texture_width * scale, m_embedded.texture_height * scale) );
	}
}

void CImageDemoView::on_exit( ) {
    m_embedded = {};
}
