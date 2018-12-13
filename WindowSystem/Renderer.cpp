#include "Renderer.h"
#include "../WindowSystem/Window.h"
#include "../Utilities/Utilities.h"

Renderer::Renderer(Window* l_window) : m_window(l_window),
    m_drawing(false), m_drawCalls(0) {}

void Renderer::BeginDrawing() { m_drawing = true; m_drawCalls = 0; }
bool Renderer::IsDrawing() const { return m_drawing; }
void Renderer::EndDrawing() { m_drawing = false; }

void Renderer::Draw(const sf::Shape& l_shape, sf::RenderTarget* l_target) {
	if (!l_target) {
		if (!m_window->GetViewSpace().intersects(l_shape.getGlobalBounds())) { return; }
	}
	Draw((const sf::Drawable&)l_shape, l_target);
}

void Renderer::Draw(const sf::Sprite& l_sprite, sf::RenderTarget* l_target) {
	if (!l_target) {
		if (!m_window->GetViewSpace().intersects(l_sprite.getGlobalBounds())) { return; }
	}
	Draw((const sf::Drawable&)l_sprite, l_target);
}

void Renderer::Draw(const sf::Drawable& l_drawable, sf::RenderTarget* l_target) {
	if (!l_target) { l_target = m_window->GetRenderWindow(); }
    l_target->draw(l_drawable, sf::RenderStates::Default);
	++m_drawCalls;
}
