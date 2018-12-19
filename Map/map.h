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

    void drawMap(sf::RenderWindow *w, sf::View v);

    void setContext(SharedContext *context);

    Tile *getTileAt(int x, int y);
private:
    SharedContext *m_context;
    Tile*** m_tiles;
    int m_width;
    int m_length;
};

#endif // MAP_H
