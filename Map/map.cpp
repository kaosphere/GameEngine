#include "map.h"
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utilities/Utilities.h"
#include "Utilities/Helpers.h"

Map::Map()
{
    //AddFile("media/maps/gen.map");
    m_tiles = nullptr;
    m_heigth = 0;
    m_width = 0;
    sorted = false;
    m_vertices.setPrimitiveType(sf::Quads);
}

Map::~Map()
{
    for (int i=0; i<m_heigth; ++i) {
        free(m_tiles[i]);
    }
    free(m_tiles);
}

bool Map::ProcessLine(std::stringstream &l_stream)
{
    std::string resource;
    std::vector<std::string> tokens = Utils::splitLine(l_stream.str(), std::string(" "));

    if(tokens.size()) {
        if(tokens[0] == "Size") {
            // load the tileset TODO : put tileset in map file directly
            m_context->m_textureManager->RequireResource("tileset");
            m_tileset = *m_context->m_textureManager->GetResource("tileset");

            // Get map dimentions
            m_heigth = std::stoi(tokens[1]);
            m_width = std::stoi(tokens[2]);
            if(m_heigth == 0 || m_width ==0) {
                return false;
            }

            // Allocate tile map
            m_tiles = new Tile**[m_heigth];
            for (int i = 0; i < m_heigth; ++i) {
	            m_tiles[i] = new  Tile*[m_width];
            }
        }

        else if(tokens[0] == "Tile") {
	        int tileType = std::stoi(tokens[1]);
	        int i = std::stoi(tokens[2]);
	        int j = std::stoi(tokens[3]);

            // on en déduit sa position dans la texture du tileset
            int tu = (int)tileType % (m_tileset.getSize().x / TILE_WIDTH);
            int tv = (int)tileType / (m_tileset.getSize().x / TILE_WIDTH);

            m_tiles[std::stoi(tokens[2])][std::stoi(tokens[3])] = new Tile(sf::Vector2f(std::stoi(tokens[2]), std::stoi(tokens[3])),
	            std::stoi(tokens[4]),
	            (TileType)std::stoi(tokens[1]),
	            sf::Vector2u(tu, tv));
        }
    }

    return true;
}

void Map::sortMapTiles()
{
    bool incY = false;
    bool decX = true;
    bool firstHalfDone = false;
    int yCurrent = 0;
    int xCurrent = 0;

    // sort tiles from top of the diamond shape to the botom
    for (int i = 0; i < (m_heigth); ++i) {
	    for (int j = 0; j < m_width; ++j) {
		    if (!firstHalfDone) {
			    yCurrent = i - j;
			    xCurrent = j;
		    }
		    else {
			    yCurrent = m_width - 1 - j;
			    xCurrent = i + j;
		    }
		    std::cout << "Coord : " << xCurrent << ", " << yCurrent << std::endl;
		    if (xCurrent >= 0 && xCurrent < m_heigth && yCurrent >= 0 && yCurrent < m_width) {
			    m_tiles[xCurrent][yCurrent]->addVerticesToArray(&m_vertices);
		    }
		    else {
			    break;
		    }
		    // Once we sorted the first top height of the map, compute the second half
		    if (xCurrent == m_width - 1 && !firstHalfDone) {
			    i = 0;
			    firstHalfDone = true;
		    }
	    }
    }
    sorted = true;
}

Tile* Map::getTileAt(int x, int y)
{
	return NULL;
	//return std::find_if(m_tiles.begin(), m_tiles.end(), TileComp(x,y))->get();
}

sf::Vector2i Map::getWorldCoord(sf::Vector2f screenPos)
{
    return sf::Vector2i(screenPos.x / TILE_WIDTH - screenPos.y / TILE_HEIGTH ,
                        screenPos.x / TILE_WIDTH + screenPos.y / TILE_HEIGTH);
}

void Map::update(float l_time)
{

}

void Map::drawMap(sf::RenderWindow *w, sf::FloatRect viewSpace)
{
    if(w == NULL) {
        return;
    }

    if (!sorted) {
	    sortMapTiles();
    }

    sf::RenderStates states;

    // on applique la texture du tileset
    states.texture = &m_tileset;

    // et on dessine enfin le tableau de vertex
    w->draw(m_vertices, states);
}

void Map::setContext(SharedContext *context)
{
    m_context = context;
}
