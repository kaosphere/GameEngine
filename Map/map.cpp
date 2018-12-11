#include "map.h"
#include <algorithm>
#include <iostream>
#include "Utilities/Utilities.h"
#include "Utilities/Helpers.h"

Map::Map(TextureManager *t)
{
    m_texMgr = t;

    loadMapFromFile("media/maps/gen.map");

    sortMapTiles();
}

bool Map::loadMapFromFile(std::__cxx11::string path)
{
    std::ifstream file(path);
    std::string line;
    std::string token;
    std::string resource;
    std::shared_ptr<Tile> p = NULL;

    while (std::getline(file, line)) {
        std::stringstream keystream(line);
        std::vector<std::string> tokens = Utils::splitLine(line, std::string(" "));

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
                }

                m_texMgr->RequireResource(resource);
                p = std::make_shared<Tile>(sf::Vector2f(std::stoi(tokens[2]),std::stoi(tokens[3])),
                                           std::stoi(tokens[4]),
                                           (TileType)std::stoi(tokens[1]),
                                           *m_texMgr->GetResource(resource));
                m_tiles.emplace_back(p);
            }
        }
    }
    file.close();
}

void Map::sortMapTiles()
{
    std::sort(m_tiles.begin(), m_tiles.end(), Utils::PComp<Tile>);
}

void Map::drawMap(sf::RenderWindow *w)
{
    if(w == NULL) return;

    for(auto iter = m_tiles.begin(); iter != m_tiles.end(); ++iter) {
        w->draw((*iter)->tileSprite());
    }
}

