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

int main()
{
    int cnt =0;
    initializeSystem();

    std::shared_ptr<Entity> p(new Entity());
    Entity test2;
    SystemManager manager;
    manager.addSystem<System_Move>(Movement);

    p->addComponent<Component_Position>(position);
    p->addComponent<Component_Speed>(speed);
    test2.addComponent<Component_Position>(position);

    manager.registerEntity(p);

    while(cnt!=20) {
        manager.update(1.0);
        cnt++;
    }

    return EXIT_SUCCESS;
}
