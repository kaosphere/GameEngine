#ifndef RENDERER_H
#define RENDERER_H

#include <unordered_map>
#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Window;

class Renderer {
    friend Window;
public:
    Renderer(Window* l_window);

	void BeginDrawing();
	bool IsDrawing()const;
	void Draw(const sf::Shape& l_shape, sf::RenderTarget* l_target = nullptr);
	void Draw(const sf::Sprite& l_sprite, sf::RenderTarget* l_target = nullptr);
	void Draw(const sf::Drawable& l_drawable, sf::RenderTarget* l_target = nullptr);
	void EndDrawing();
private:
	Window* m_window;
	bool m_drawing;
	unsigned int m_drawCalls;
};

#endif //RENDERER_H
