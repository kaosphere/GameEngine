#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <string>

#define OUTPUT_PATH "media/maps/"

class MapGenerator
{
public:
    MapGenerator();
    static bool generateMap(int width, int length, std::string name);

    int m_x;
    int m_y;
    std::string m_name;
};

#endif // MAPGENERATOR_H
