#include "tile.h"

Tile::Tile()
{

}

Tile::Tile(sf::Vector2f wp, int z, TileType type,
           const sf::Texture &top,
           const sf::Texture &root,
           const sf::Texture &wall)
{
    m_worldPos = wp;
    m_z = z;
    m_type = type;
    m_wallSprites.clear();

    loadTopSprite(top);
    loadRootSprite(root);
    loadWallSprites(wall);
    updateScreenPos();
}

Tile::~Tile()
{

}

float Tile::z() const
{
    return m_z;
}

void Tile::setZ(float z)
{
    m_z = z;
}

sf::Sprite* Tile::tileTopSprite() {
    return &m_topSprite;
}

sf::Sprite *Tile::tileRootSprite()
{
    return &m_rootSprite;
}

std::vector<sf::Sprite*> *Tile::tileWallSprites()
{
    return &m_wallSprites;
}

void Tile::loadTopSprite(const sf::Texture &t)
{
    m_topSprite.setTexture(t);
}

void Tile::loadRootSprite(const sf::Texture &t)
{
    m_rootSprite.setTexture(t);
}

void Tile::loadWallSprites(const sf::Texture &t)
{
    // Start to 1 because of the root sprite
    for (int i=1; i < m_z; ++i) {
        sf::Sprite *sp = new sf::Sprite;
        sp->setTexture(t);
        m_wallSprites.emplace_back(sp);
    }
}


sf::Vector2f Tile::screenPos() const
{
    return m_screenPos;
}

void Tile::updateScreenPos()
{
    m_screenPos.x = (m_worldPos.x + m_worldPos.y) * (TILE_WIDTH/2);
    m_screenPos.y = (-m_worldPos.x + m_worldPos.y) * (TILE_HEIGTH/2);
    m_topSprite.setPosition(m_screenPos.x, m_screenPos.y - m_z * TILE_HEIGTH);

    if(m_z > 0) {
        m_rootSprite.setPosition(m_screenPos.x, m_screenPos.y);
        // Start to 1 because of the root sprite
        int i = 1;
        for(auto spriteItr : m_wallSprites) {
            spriteItr->setPosition(m_screenPos.x, m_screenPos.y - i++ * TILE_HEIGTH);
        }
    }
}

/**
 * @brief Tile::operator < This operator is design to sort the tiles from the back of the map to the front
 * in order to be drawn in the correct order.
 * @param rhs
 * @return
 */
bool Tile::operator<(const Tile &rhs)
{
    return (worldPos().y < rhs.worldPos().y) ||
            (worldPos().x > rhs.worldPos().x);
}

sf::Vector2f Tile::worldPos() const
{
    return m_worldPos;
}

bool Tile::isInLocation(int x, int y)
{
    return (m_worldPos.x == x && m_worldPos.y == y);
}

void Tile::setWorldPos(const sf::Vector2f &worldPos)
{
    m_worldPos = worldPos;
    updateScreenPos();
}

