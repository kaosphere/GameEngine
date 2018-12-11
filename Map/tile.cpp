#include "tile.h"

Tile::Tile()
{

}

Tile::Tile(sf::Vector2f wp, int z, TileType type, const sf::Texture &t)
{
    m_worldPos = wp;
    m_z = z;
    m_type = type;

    updateScreenPos();
    loadSprite(t);
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

sf::Sprite Tile::tileSprite() const
{
    return m_tileSprite;
}

void Tile::loadSprite(const sf::Texture &t)
{
    m_tileSprite.setTexture(t);
}

sf::Vector2f Tile::screenPos() const
{
    return m_screenPos;
}

void Tile::updateScreenPos()
{
    m_screenPos.x = (m_worldPos.x + m_worldPos.y) * (TILE_LENGTH/2) - 500;
    m_screenPos.y = (-m_worldPos.x + m_worldPos.y) * (TILE_WIDTH/2) + 500;
    m_tileSprite.setPosition(m_screenPos.x, m_screenPos.y);
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

void Tile::setWorldPos(const sf::Vector2f &worldPos)
{
    m_worldPos = worldPos;
    updateScreenPos();
}

