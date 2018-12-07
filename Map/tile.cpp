#include "tile.h"

Tile::Tile()
{

}

Tile::Tile(sf::Vector2f wp, int z, TileType type)
{
    m_worldPos = wp;
    m_z = z;
    m_type = type;
}

int Tile::z() const
{
    return m_z;
}

void Tile::setZ(int z)
{
    m_z = z;
}

sf::Sprite Tile::tileSprite() const
{
    return m_tileSprite;
}

void Tile::loadSprite(type)
{
    switch(type)
    {
    case grass:
        break;

    default:
        // Invalid type, TODO
        break;
    }
}

sf::Vector2f Tile::worldPos() const
{
    return m_worldPos;
}

void Tile::setWorldPos(const sf::Vector2f &worldPos)
{
    m_worldPos = worldPos;
}

