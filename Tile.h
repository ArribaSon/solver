#ifndef SOLVER_TILE_H
#define SOLVER_TILE_H
#include <string>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Tile {

private:

    string *path;
    int N;
    unsigned char ***color;

public:
    Tile();

    Tile(string *path);

    ~Tile();

    Tile(Tile *pTile);

    string getPath(){
        return *path;
    }

    static void createPicture();


};


#endif
