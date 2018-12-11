#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "inits.h"
#include "ECS/Core/entity.h"
#include "ECS/Core/componenttypes.h"
#include "ECS/Components/component_position.h"
#include "ECS/Components/component_speed.h"
#include "ECS/Systems/system_move.h"
#include "ECS/Core/system_base.h"
#include "Resources/TextureManager.h"
#include "Map/map.h""
#include "Map/mapgenerator.h"

int main()
{
    int cnt =0;
    initializeSystem();

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::View mainView(sf::FloatRect(0, 0, 800, 600));

    MapGenerator::generateMap(50,50,"gen");

    TextureManager tex;
    Map m(&tex);

    std::shared_ptr<Entity> p(new Entity());
    Entity test2;
    SystemManager manager;
    manager.addSystem<System_Move>(Movement);

    p->addComponent<Component_Position>(position);
    p->addComponent<Component_Speed>(speed);
    test2.addComponent<Component_Position>(position);

    manager.registerEntity(p);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::W)
                    {
                        mainView.move(0,-10);
                    }
                    if (event.key.code == sf::Keyboard::S)
                    {
                        mainView.move(0,10);
                    }
                    if (event.key.code == sf::Keyboard::A)
                    {
                        mainView.move(-10,0);
                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                        mainView.move(10,0);
                    }
                }
            if(event.type == sf::Event::MouseWheelScrolled) {
                //mainView.zoom(event.mouseWheelScroll.delta);
                if(event.mouseWheelScroll.delta == -1) {
                    mainView.zoom(0.5);
                }
                else {
                    mainView.zoom(1.5);
                }
            }
        }
        // Clear screen
        window.clear();

        window.setView(mainView);

        m.drawMap(&window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
