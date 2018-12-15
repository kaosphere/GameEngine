#include "map.h"
#include <algorithm>
#include <iostream>
#include "Utilities/Utilities.h"
#include "Utilities/Helpers.h"

Map::Map()
{
    //AddFile("media/maps/gen.map");
}

bool Map::ProcessLine(std::stringstream &l_stream)
{
    std::string resource;
    std::shared_ptr<Tile> p = nullptr;

    std::vector<std::string> tokens = Utils::splitLine(l_stream.str(), std::string(" "));

    if(tokens.size()) {
        if(tokens[0] == "Tile") {
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
            p = std::make_shared<Tile>(sf::Vector2f(std::stoi(tokens[2]),std::stoi(tokens[3])),
                                       std::stoi(tokens[4]),
                                       (TileType)std::stoi(tokens[1]),
                                       *m_context->m_textureManager->GetResource(resource),
                                        *m_context->m_textureManager->GetResource("tile-bot"),
                                        *m_context->m_textureManager->GetResource("tile-mid"));
            m_tiles.emplace_back(p);
        }
    }

    return true;
}

void Map::sortMapTiles()
{
    std::sort(m_tiles.begin(), m_tiles.end(), Utils::PComp<Tile>);
}

void Map::update(float l_time)
{

}

void Map::drawMap(sf::RenderWindow *w)
{
    if(w == NULL) return;

    for(auto iter = m_tiles.begin(); iter != m_tiles.end(); ++iter) {
        std::vector<sf::Sprite*> *wall = (*iter)->tileWallSprites();
        w->draw(*((*iter)->tileTopSprite()));
        if((*iter)->z() > 0) {
            w->draw(*((*iter)->tileRootSprite()));
            for(auto wallItr : *wall) {
                w->draw(*wallItr);
            }
        }
    }
}

void Map::setContext(SharedContext *context)
{
    m_context = context;
}
