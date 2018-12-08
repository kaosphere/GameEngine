#ifndef MAP_H
#define MAP_H

#include <list>
#include <memory>
#include <SFML/Window.hpp>
#include "Resources/TextureManager.h"
#include "tile.h"

class Map
{
public:
    Map(TextureManager *t);

    bool loadMapFromFile(std::string path);

    void drawMap(sf::RenderWindow *w);

private:
    TextureManager *m_texMgr;
    std::list<std::shared_ptr<Tile> > m_tiles;
};

#endif // MAP_H
