#include "Map/mapgenerator.h"
#include "inits.h"
#include "game.h"

int main()
{
    initializeSystem();

    MapGenerator::generateMap(25,25,"gen");

    Game g;

    while(!g.GetWindow()->IsDone()) {
        g.Update();
        g.Render();
        g.LateUpdate();
    }

    return EXIT_SUCCESS;
}
