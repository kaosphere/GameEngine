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
            m_heigth = std::stoi(tokens[1]);
            m_width = std::stoi(tokens[2]);
            if(m_heigth == 0 || m_width ==0) {
                return false;
            }
            m_tiles = new Tile**[m_heigth];
            for(int i = 0; i < m_heigth; ++i) {
                m_tiles[i] = new  Tile*[m_width];
            }
        }

        else if(tokens[0] == "Tile" && m_tiles != nullptr) {
            switch((TileType)std::stoi(tokens[1]))
            {
            case sand:
                resource = "tile-top-sand";
                break;
            case arid:
                resource = "tile-top-arid";
                break;
            case grass:
                resource = "tile-top-grass";
                break;
            case jungle:
                resource = "tile-top-jungle";
                break;
            case water:
                resource = "tile-top-water";
                break;
            default:
                break;
            }

            m_context->m_textureManager->RequireResource(resource);
            for (int i = 0; i < std::stoi(tokens[4]); ++i) {
                m_context->m_textureManager->RequireResource("tile-mid");
            }
            m_context->m_textureManager->RequireResource("tile-bot");

            // Add tile in the map
            m_tiles[std::stoi(tokens[2])][std::stoi(tokens[3])] = new Tile(sf::Vector2f(std::stoi(tokens[2]),std::stoi(tokens[3])),
                                       std::stoi(tokens[4]),
                                       (TileType)std::stoi(tokens[1]),
                                       *m_context->m_textureManager->GetResource(resource),
                                        *m_context->m_textureManager->GetResource("tile-bot"),
                                        *m_context->m_textureManager->GetResource("tile-mid"));

        }
    }

    return true;
}

void Map::sortMapTiles()
{
    //std::sort(m_tiles.begin(), m_tiles.end(), Utils::PComp<Tile>);
}

Tile* Map::getTileAt(int x, int y)
{
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

    sf::Vector2i coordStart = getWorldCoord(sf::Vector2f(viewSpace.left, viewSpace.top));
    int nWidth = (viewSpace.width / TILE_WIDTH) + 2;
    int nHeight = (viewSpace.height / TILE_HEIGTH) + 2;

    //std::cout << coordStart.x << "," << coordStart.y << "," << nWidth << "," << nHeight << std::endl;

//    sf::FloatRect r(viewSpace.left, viewSpace.top,viewSpace.width, viewSpace.height);
//    std::cout << r.top << "," << r.left << "," << r.width << "," << r.height << std::endl;
//    // New Algo :
//    // - get visible area, deduce what tiles are visible
//    // - Iterate in right order on all those tiles
//    for(int i = 0; i < m_heigth; ++i) {
//        for(int y = 0; y < m_width; ++y) {
//            if(r.intersects(m_tiles[i][y]->tileTopSprite()->getGlobalBounds())) {
//                w->draw(*m_tiles[i][y]->tileTopSprite());
//                if(m_tiles[i][y]->z() > 0) {
//                    std::vector<sf::Sprite*> *wall = m_tiles[i][y]->tileWallSprites();
//                    w->draw(*m_tiles[i][y]->tileRootSprite());
//                    for(auto wallItr : *wall) {
//                        w->draw(*wallItr);
//                    }
//                }
//            }
//        }
//    }

    // Calculate xStart, yStart, nWidth and nHight based on the viewport
    bool incY = false;
    bool decX = true;
    int y = coordStart.y;
    int x = coordStart.x;
    for(int i = 0; i < (nHeight*2); ++i) {
        if (x < 0) {
            if (y > (nWidth-1)) {
                continue;
            }
            x = 0;
            incY = true;
        }
        //else if(y >= coordStart.y) incY = false;
        incY ? y++ : y;
        for(int j = 0; j < nWidth; ++j) {
           int yCurrent = y + j;
           int xCurrent = x + j;
           //std::cout << "Coord : " << xCurrent << ", " << yCurrent;
           if(xCurrent >= 0 && xCurrent < m_heigth && yCurrent >= 0 && yCurrent < m_width) {
               if(yCurrent < m_heigth -1) {
                   if(m_tiles[xCurrent][yCurrent+1]->z() > m_tiles[xCurrent][yCurrent]->z()){
                       continue;
                   }
               }
               w->draw(*m_tiles[xCurrent][yCurrent]->tileTopSprite());
               if(m_tiles[xCurrent][yCurrent]->z() > 0) {
                   std::vector<sf::Sprite*> *wall = m_tiles[xCurrent][yCurrent]->tileWallSprites();
                   w->draw(*m_tiles[xCurrent][yCurrent]->tileRootSprite());
                   for(auto wallItr : *wall) {
                       w->draw(*wallItr);
                   }
               }
               //std::cout << " drawn.";
           }
           //std::cout << std::endl;
        }
        incY = !incY;
        if(!incY) x--;
    }

    //std::cout << "Stop." << std::endl;
}

void Map::setContext(SharedContext *context)
{
    m_context = context;
}
