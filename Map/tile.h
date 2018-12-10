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


#define TILE_LENGTH 100
#define TILE_WIDTH 50
#define OFFSET 200

class Tile
{
public:
    Tile();
    Tile(sf::Vector2f wp, int z, TileType type, const sf::Texture& t);
    ~Tile();

    float z() const;
    void setZ(float z);

    sf::Sprite tileSprite() const;

    sf::Vector2f worldPos() const;
    void setWorldPos(const sf::Vector2f &worldPos);

    sf::Vector2f screenPos() const;

    void updateScreenPos();

    bool operator< (const Tile& rhs);

private:
    void loadSprite(const sf::Texture &t);

    TileType m_type;
    sf::Sprite m_tileSprite;

    sf::Vector2f m_worldPos;
    sf::Vector2f m_screenPos;
    float m_z;
};

#endif // TILE_H
