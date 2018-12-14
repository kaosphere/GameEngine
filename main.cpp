#include "Map/mapgenerator.h"
#include "inits.h"
#include "game.h"

int main()
{
    initializeSystem();

    MapGenerator::generateMap(50,50,"gen");

    Game g;

    while(!g.GetWindow()->IsDone()) {
        g.Update();
        g.Render();
        g.LateUpdate();
    }

    return EXIT_SUCCESS;
}
