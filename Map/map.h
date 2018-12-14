#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include "Resources/TextureManager.h"
#include "tile.h"
#include "SharedContext.h"
#include "ThreadWorkers/FileLoader.h"

class Map : public FileLoader
{
public:
    Map();

    virtual bool ProcessLine(std::stringstream& l_stream);

    void sortMapTiles();

    void update(float l_time);

    void drawMap(sf::RenderWindow *w);

    void setContext(SharedContext *context);

private:
    SharedContext *m_context;
    std::vector<std::shared_ptr<Tile> > m_tiles;
};

#endif // MAP_H
