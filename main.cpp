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
#include "Utilities/SimplexNoise.h"

int main()
{
    int cnt =0;
    initializeSystem();
    float x = 1.0;
    float y = x;
    float noise = SimplexNoise::noise(x,y);

    std::cout << "Noise : " << noise << std::endl;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

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
        }
        // Clear screen
        window.clear();

        m.drawMap(&window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
