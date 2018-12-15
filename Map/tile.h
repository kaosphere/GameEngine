#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum TileType {
    _invalidTileType,
    grass,
    arid,
    sand,
    water,
    jungle,
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
    Tile(sf::Vector2f wp, int z, TileType type,
         const sf::Texture& top,
         const sf::Texture& root,
         const sf::Texture& wall);
    ~Tile();

    float z() const;
    void setZ(float z);

    sf::Sprite* tileTopSprite();
    sf::Sprite *tileRootSprite();
    std::vector<sf::Sprite *> *tileWallSprites();

    sf::Vector2f worldPos() const;
    void setWorldPos(const sf::Vector2f &worldPos);

    sf::Vector2f screenPos() const;

    void updateScreenPos();

    bool operator< (const Tile& rhs);

private:
    void loadTopSprite(const sf::Texture &t);
    void loadRootSprite(const sf::Texture &t);
    void loadWallSprites(const sf::Texture &t);

    TileType m_type;
    std::vector<sf::Sprite*> m_wallSprites;
    sf::Sprite m_topSprite;
    sf::Sprite m_rootSprite;

    sf::Vector2f m_worldPos;
    sf::Vector2f m_screenPos;
    float m_z;
};

#endif // TILE_H
