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
#include "Map/map.h"
#include "Map/mapgenerator.h"
#include "WindowSystem/Window.h"

int main()
{
    initializeSystem();

    // Create the main window
    Window win("SFML window", sf::Vector2u(800, 600));
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

    win.GetRenderWindow()->setView(mainView);

    // Start the game loop
    while (!win.IsDone())
    {
        win.Update(&mainView);

        win.BeginDraw();

        win.GetRenderWindow()->setView(mainView);

        m.drawMap(win.GetRenderWindow());

        win.EndDraw();
    }

    return EXIT_SUCCESS;
}
