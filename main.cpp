#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ECS/Core/entity.h"
#include "ECS/Core/componenttypes.h"
#include "ECS/Components/component_position.h"

int main()
{
    Entity test;
    Entity test2;

    test.addComponent<Component_Position>(position);
    test2.addComponent<Component_Position>(position);
    std::cout << test.getInfo();
    std::cout << test2.getInfo();

    return EXIT_SUCCESS;
}
