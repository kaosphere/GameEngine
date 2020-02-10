#include "Map/mapgenerator.h"
#include "inits.h"
#include "game.h"
#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main()
{
#ifdef __linux__
    XInitThreads();
#endif
    initializeSystem();

    MapGenerator::generateMap(100,100,"gen");

    Game g;

    while(!g.GetWindow()->IsDone()) {
        g.Update();
        g.Render();
        g.LateUpdate();
    }

    return EXIT_SUCCESS;
}
