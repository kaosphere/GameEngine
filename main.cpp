#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "inits.h"
#include "ECS/Core/entity.h"
#include "ECS/Core/componenttypes.h"
#include "ECS/Components/component_position.h"
#include "ECS/Components/component_speed.h"

int main()
{
    initializeSystem();

    Entity test;
    Entity test2;

    test.addComponent<Component_Position>(position);
    test.addComponent<Component_Speed>(speed);
    test2.addComponent<Component_Position>(position);
    std::cout << test.getInfo();
    std::cout << test2.getInfo();

    return EXIT_SUCCESS;
}
