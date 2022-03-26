#include "Tile.h"

Tile::Tile() {

}

Tile::Tile(string *path) {
    this->path = path;
    ifstream file(this->path->c_str());
    string buffer;
    if (file.is_open()) {
        if (!file.eof()) file >> buffer;
        if (!file.eof()) file >> buffer;
        if (!file.eof()) file >> buffer;
        N = stoi(buffer);
        if (!file.eof()) file >> buffer;


        color = new unsigned char **[N];
        for (int i = 0; i < N; i++) {
            color[i] = new unsigned char *[N];
            for (int j = 0; j < N; j++) {
                color[i][j] = new unsigned char[3];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 3; k++) {
                    do {
                        if (!file.eof())file >> buffer;
                        else break;
                    } while (buffer.empty());
                    color[i][j][k] = (unsigned char) stoi(buffer);

                }
            }
        }
    }
    file.close();
}

Tile::~Tile() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            delete [] color[i][j];
        }
        delete [] color[i];
    }
    delete [] color;
}

Tile::Tile(Tile *pTile) {
    path = pTile->path;
    N = pTile->N;
    color = new unsigned char **[N];
    for (int i = 0; i < N; i++) {
        color[i] = new unsigned char *[N];
        for (int j = 0; j < N; j++) {
            color[i][j] = new unsigned char[3];
            for (int k = 0; k < 3; k++) {
                color[i][j][k] = pTile->color[i][j][k];
            }
        }
    }

}

void Tile::createPicture() {
    ofstream out;
    out.open("image.ppm");
    if(out.is_open()){
        //out<<"P3\n"<<to_string(N)<<" "<<to_string(N)<<"\n"<<"255";
    }
}



