#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Resources/TextureManager.h"
#include "tile.h"
#include "SharedContext.h"
#include "ThreadWorkers/FileLoader.h"


// Every loop and calculation based on : http://clintbellanger.net/articles/isometric_math/
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
    sf::VertexArray m_vertices;
    sf::VertexArray m_sortedVertices;
    sf::Texture m_tileset;
    int m_heigth;
    int m_width;
    bool sorted;
};

#endif // MAP_H
