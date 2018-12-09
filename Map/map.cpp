#include "map.h"
#include <algorithm>
#include <Utilities/Utilities.h>

Map::Map(TextureManager *t)
{
    m_texMgr = t;

    std::shared_ptr<Tile> p = NULL;
    t->RequireResource("tile-top");
    p = std::make_shared<Tile>(sf::Vector2f(0,0),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);
    p = std::make_shared<Tile>(sf::Vector2f(1,0),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);
    p = std::make_shared<Tile>(sf::Vector2f(2,0),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);
    p = std::make_shared<Tile>(sf::Vector2f(0,1),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);
    p = std::make_shared<Tile>(sf::Vector2f(1,1),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);
    p = std::make_shared<Tile>(sf::Vector2f(2,1),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);
    p = std::make_shared<Tile>(sf::Vector2f(0,2),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);
    p = std::make_shared<Tile>(sf::Vector2f(1,2),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);
    p = std::make_shared<Tile>(sf::Vector2f(2,2),0,grass, *t->GetResource("tile-top"));
    m_tiles.emplace_back(p);

    sortMapTiles();
}

bool Map::loadMapFromFile(std::__cxx11::string path)
{

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

