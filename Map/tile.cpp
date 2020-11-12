#include "tile.h"

Tile::Tile()
{

}

Tile::Tile(sf::Vector2f wp, int z, TileType type, sf::Vector2u textPos)
{
    m_worldPos = wp;
    m_z = z;
    m_type = type;
    m_texturePos = textPos;

    m_tileVertices.setPrimitiveType(sf::Quads);
    m_tileVertices.resize(4);

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

sf::Vector2f Tile::screenPos() const
{
    return m_screenPos;
}

void Tile::updateScreenPos()
{
    m_screenPos.x = (m_worldPos.x - m_worldPos.y) * (TILE_WIDTH/2);
    m_screenPos.y = (m_worldPos.x + m_worldPos.y) * (TILE_HEIGTH/2);

    // on définit ses quatre coins
    m_tileVertices[0].position = sf::Vector2f(m_screenPos.x, m_screenPos.y); // coin en haut a gauche
    m_tileVertices[1].position = sf::Vector2f(m_screenPos.x + TILE_WIDTH, m_screenPos.y);  // coin en haut a droite
    m_tileVertices[2].position = sf::Vector2f(m_screenPos.x + TILE_WIDTH, m_screenPos.y + TILE_HEIGTH); // coin en bas a droite
    m_tileVertices[3].position = sf::Vector2f(m_screenPos.x, m_screenPos.y + TILE_HEIGTH);  // coin en bas a gauche

    // on définit ses quatre coordonnées de texture
    m_tileVertices[0].texCoords = sf::Vector2f((m_texturePos.x)* TILE_WIDTH, (m_texturePos.y)* TILE_HEIGTH);
    m_tileVertices[1].texCoords = sf::Vector2f((m_texturePos.x + 1) * TILE_WIDTH, (m_texturePos.y)* TILE_HEIGTH);
    m_tileVertices[2].texCoords = sf::Vector2f((m_texturePos.x + 1) * TILE_WIDTH, (m_texturePos.y + 1) * TILE_HEIGTH);
    m_tileVertices[3].texCoords = sf::Vector2f((m_texturePos.x)* TILE_WIDTH, (m_texturePos.y + 1) * TILE_HEIGTH);
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

void Tile::addVerticesToArray(sf::VertexArray * vertArray)
{
    vertArray->append(m_tileVertices[0]);
    vertArray->append(m_tileVertices[1]);
    vertArray->append(m_tileVertices[2]);
    vertArray->append(m_tileVertices[3]);
}

void Tile::setWorldPos(const sf::Vector2f &worldPos)
{
    m_worldPos = worldPos;
    updateScreenPos();
}

