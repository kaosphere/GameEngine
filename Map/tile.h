#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum TileType {
    _invalidTileType,
    grass,
    rock,
    sand,
    snow,
    tileCOUNT
};


class Tile
{
public:
    Tile();
    Tile(sf::Vector2f wp, int z, TileType type);

    int z() const;
    void setZ(int z);

    sf::Sprite tileSprite() const;

    sf::Vector2f worldPos() const;
    void setWorldPos(const sf::Vector2f &worldPos);

private:
    void loadSprite(type);

    TileType m_type;
    sf::Sprite m_tileSprite;

    sf::Vector2f m_worldPos;
    int m_z;
};

#endif // TILE_H
