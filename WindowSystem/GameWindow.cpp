#include "GameWindow.h"

GameWindow::GameWindow(const std::string& l_title, const sf::Vector2u& l_size) : m_renderer(this){
	Setup(l_title, l_size);
}

GameWindow::~GameWindow() { m_window.close(); }

void GameWindow::Setup(const std::string& l_title, const sf::Vector2u& l_size) {
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	m_isFocused = true;

    m_eventManager.AddCallback(StateType(0), "Fullscreen_toggle", &GameWindow::ToggleFullscreen, this);
    m_eventManager.AddCallback(StateType(0), "Window_close", &GameWindow::Close, this);

	Create();
}

void GameWindow::Create() {
	sf::Uint32 style = sf::Style::Default;
	if(m_isFullscreen) { style = sf::Style::Fullscreen; }

	sf::ContextSettings settings;
    /*settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 0;
    settings.majorVersion = 4;
    settings.minorVersion = 5;*/

	m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y, 32), m_windowTitle, style, settings);
}

void GameWindow::BeginDraw() { m_window.clear(sf::Color::Black); m_renderer.BeginDrawing(); }
void GameWindow::EndDraw() { m_window.display(); m_renderer.EndDrawing(); }

bool GameWindow::IsDone() const { return m_isDone; }
bool GameWindow::IsFullscreen() const { return m_isFullscreen; }
bool GameWindow::IsFocused() const { return m_isFocused; }

sf::RenderWindow* GameWindow::GetRenderWindow() { return &m_window; }
Renderer* GameWindow::GetRenderer() { return &m_renderer; }
EventManager* GameWindow::GetEventManager() { return &m_eventManager; }
sf::Vector2u GameWindow::GetWindowSize() const { return m_windowSize; }
sf::FloatRect GameWindow::GetViewSpace() const {
	sf::Vector2f viewCenter(m_window.getView().getCenter());
	sf::Vector2f viewSize(m_window.getView().getSize());
	sf::Vector2f viewSizeHalf(viewSize.x / 2, viewSize.y / 2);
	sf::FloatRect viewSpace(viewCenter - viewSizeHalf, viewSize);
	return viewSpace;
}

void GameWindow::ToggleFullscreen(EventDetails* l_details) {
	m_isFullscreen = !m_isFullscreen;
	m_window.close();
	Create();
}

void GameWindow::Close(EventDetails* l_details) { m_isDone = true; }

void GameWindow::Update() { //TODO : remove view from here
	sf::Event event;

    while(m_window.pollEvent(event)) {
        if (event.type == sf::Event::LostFocus) { m_isFocused = false; m_eventManager.SetFocus(false); }
		else if (event.type == sf::Event::GainedFocus) { m_isFocused = true; m_eventManager.SetFocus(true); }
		m_eventManager.HandleEvent(event);
	}

    m_eventManager.Update();
}
