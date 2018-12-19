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
    m_width = 0;
    m_length = 0;
}

Map::~Map()
{
    for (int i=0; i<m_width; ++i) {
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
            m_width = std::stoi(tokens[1]);
            m_length = std::stoi(tokens[2]);
            if(m_width == 0 || m_length ==0) {
                return false;
            }
            m_tiles = new Tile**[m_width];
            for(int i = 0; i < m_width; ++i) {
                m_tiles[i] = new  Tile*[m_length];
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

void Map::update(float l_time)
{

}

void Map::drawMap(sf::RenderWindow *w, sf::View v)
{
    if(w == NULL) {
        return;
    }

    // New Algo :
    // - get visible area, deduce what tiles are visible
    // - Iterate in right order on all those tiles
    for(int i = 0; i < m_width; ++i) {
        for(int y = 0; y < m_length; ++y) {
            sf::FloatRect r(w->getViewport(v).left, w->getViewport(v).top, w->getViewport(v).width, w->getViewport(v).height);
            if(r.intersects(m_tiles[i][y]->tileTopSprite()->getGlobalBounds()))
                w->draw(*m_tiles[i][y]->tileTopSprite());
        }
    }

//    for(auto iter = m_tiles.begin(); iter != m_tiles.end(); ++iter) {
//        std::vector<sf::Sprite*> *wall = (*iter)->tileWallSprites();
//        w->draw(*((*iter)->tileTopSprite()));
//        if((*iter)->z() > 0) {

//            w->draw(*((*iter)->tileRootSprite()));
//            for(auto wallItr : *wall) {
//                w->draw(*wallItr);
//            }
//        }
//    }
}

void Map::setContext(SharedContext *context)
{
    m_context = context;
}
