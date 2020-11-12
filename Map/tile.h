#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <memory>

enum TileType {
    _invalidTileType = 0,
    grass = 2,
    jungle,
    arid,
    sand,
    water,
    snow
};


#define TILE_WIDTH 100
#define TILE_HEIGTH 50
#define OFFSET 200

class Tile
{
public:
    Tile();
    Tile(sf::Vector2f wp, int z, TileType type, sf::Vector2u textPostileType);
    ~Tile();

    float z() const;
    void setZ(float z);

    sf::Vector2f worldPos() const;
    void setWorldPos(const sf::Vector2f &worldPos);

    sf::Vector2f screenPos() const;

    void updateScreenPos();

    bool operator< (const Tile& rhs);

    bool isInLocation(int x, int y);

    void addVerticesToArray(sf::VertexArray* vertArray);

private:
    TileType m_type;
    sf::VertexArray m_tileVertices;

    sf::Vector2f m_worldPos;
    sf::Vector2f m_screenPos;
    sf::Vector2u m_texturePos;
    float m_z;
};

// Comparator object for searches
struct TileComp
{
    explicit TileComp(int x, int y) { m_x = x; m_y = y; }
    inline bool operator()(const std::shared_ptr<Tile> & m) const { return (m->worldPos().x == m_x && m->worldPos().y == m_y); }
private:
    int m_x;
    int m_y;
};

#endif // TILE_H
