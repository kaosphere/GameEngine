#include <iostream>
#include <iostream>
#include "mapgenerator.h"
#include "Utilities/SimplexNoise.h"
#include "Utilities/FastNoise.h"
#include "Map/map.h"
#include "Map/tile.h"

MapGenerator::MapGenerator()
{

}

bool MapGenerator::generateMap(int width, int length, std::string name)
{
    //SimplexNoise noiser(200.0,100.0,2.0,0.5);
    FastNoise noiser;
    //noiser.SetNoiseType(FastNoise::SimplexFractal);
    noiser.SetFrequency(0.05);
    srand (time(NULL));
    noiser.SetSeed(rand() % 999999999);
    float moistureMap[width][length];
    for(int y = 0; y < length; ++y) {
        for(int x = 0; x < width; ++x) {
            //float nx = ((float)x / (float)width) - 0.5, ny = ((float)y / (float)length) - 0.5;
            moistureMap[x][y] = noiser.GetNoise(x,y)/2 + 0.5;
        }
    }

    // Fill up map file
    std::ofstream myfile;
    myfile.open(OUTPUT_PATH + name + ".map");

    for(int y = 0; y < length; ++y) {
        for(int x = 0; x < width; ++x) {
            std::string line;
            std::stringstream lineStream;
            lineStream << "Tile ";

            if(moistureMap[x][y] < 0.2) {
                // Sand
                lineStream << sand << " ";
            }
            else if(moistureMap[x][y] < 0.4) {
                // Arid plains
                lineStream << arid << " ";
            }
            else if(moistureMap[x][y] < 0.6) {
                // Grass
                lineStream << grass << " ";
            }
            else if(moistureMap[x][y] < 0.8) {
                // Jungle
                lineStream << jungle << " ";
            }
            else {
                // Swamp
                lineStream << water << " ";
            }

            lineStream << x << " " << y << " 0" << "\n";
            line = lineStream.str();
            myfile << line;
        }
    }

    myfile.close();
}
