#include <iostream>
#include <Windows.h>
#include <vector>
#include "Tile.h"

using namespace std;

int main(int argv, char *args[]) {
    system("chcp 65001");//кодировка
    system("cls");

    //Переменные
    vector<string> path;
    string mainPath = args[1];
    Tile *tiles;
    //Проверка на аргументы
    if (argv != 2) {
        cout << "Проверте аргументы запуска";
        return 0;
    }
    //Поиск путей файлов
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    hf = FindFirstFile(args[1], &FindFileData);
    if (hf != INVALID_HANDLE_VALUE) {
        do {
            string name = string(FindFileData.cFileName);
            if (name.find(".ppm\0") != -1) {
                string str = mainPath;
                str.pop_back();
                path.push_back(str + FindFileData.cFileName);
            }
        } while (FindNextFile(hf, &FindFileData) != 0);
        FindClose(hf);
    }
    //Создание тайлов
    tiles = new Tile[path.size()];
    for(int i = 0; i < path.size(); i++){
        tiles[i] = new Tile(&path[i]);
    }




    Tile::createPicture();

    //Удаление
    //delete [] tiles;
}
