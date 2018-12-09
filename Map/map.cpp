#include "map.h"
#include <algorithm>
#include <iostream>
#include "Utilities/Utilities.h"
#include "Utilities/Helpers.h"

Map::Map(TextureManager *t)
{
    m_texMgr = t;

    loadMapFromFile("media/maps/test.map");

    sortMapTiles();
}

bool Map::loadMapFromFile(std::__cxx11::string path)
{
    std::ifstream file(path);
    std::string line;
    std::string token;
    std::shared_ptr<Tile> p = NULL;

    while (std::getline(file, line)) {
        std::stringstream keystream(line);
        std::vector<std::string> tokens = Utils::splitLine(line, std::string(" "));

        if(tokens.size()) {
            if(tokens[0] == "tile") {
                m_texMgr->RequireResource("tile-top");
                p = std::make_shared<Tile>(sf::Vector2f(std::stoi(tokens[2]),std::stoi(tokens[3])),
                                           std::stoi(tokens[4]),
                                           (TileType)std::stoi(tokens[1]),
                                           *m_texMgr->GetResource("tile-top"));
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

