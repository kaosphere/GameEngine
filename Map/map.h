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
    ~Map();

    virtual bool ProcessLine(std::stringstream& l_stream);

    void sortMapTiles();

    void update(float l_time);

    void drawMap(sf::RenderWindow *w, sf::FloatRect viewSpace);

    void setContext(SharedContext *context);

    Tile *getTileAt(int x, int y);
    sf::Vector2i getWorldCoord(sf::Vector2f screenPos);
private:
    SharedContext *m_context;
    Tile*** m_tiles;
    int m_heigth;
    int m_width;
};

#endif // MAP_H
