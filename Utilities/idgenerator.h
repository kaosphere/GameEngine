#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <string>
#include <cstdlib>
#include <time.h>

class IdGenerator
{
private:
    static const char ALPHANUM[];

public:
    static const int ID_SIZE;

    IdGenerator(){}
    static void initGenerator();
    static std::string generateRandomID(int length = ID_SIZE);
};

#endif // IDGENERATOR_H
