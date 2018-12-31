#include "gamemodel.h"

GameModel::GameModel(int size)
{
    gameTable = new Field*[size];

    for(int i = 0; i < size; ++i) {

        gameTable[i] = new Field[size];
    }
}

void GameModel::newGame(int size)
{
    delete[] gameTable;

    gameTable = new Field*[size];

    for(int i = 0; i < size; ++i) {

        gameTable[i] = new Field[size];
    }

    tableSize = size;

    for(int i = 0; i < size; ++i) {

        for(int j = 0; j < size; ++j) {

            gameTable[i][j] = GameModel::Empty;
        }
    }

    gameTable[tableSize / 2 - 1][tableSize / 2 - 1] = GameModel::White;
    gameTable[tableSize / 2][tableSize / 2] = GameModel::White;
    gameTable[tableSize / 2 - 1][tableSize / 2] = GameModel::Black;
    gameTable[tableSize / 2][tableSize / 2 - 1] = GameModel::Black;

    current = GameModel::White;
}

void GameModel::setPoint(int x, int y)
{

    if(getField(x,y) == GameModel::Empty) {

        gameTable[x][y] = current;
        current = (Field)(current % 2 + 1);
    }

    else {

        invalidSet();
    }
}

GameModel::Field GameModel::getField(int x, int y)
{
    if(x < 0 || y < 0 || x >= tableSize || y >= tableSize) {

        return GameModel::None;
    }

    return gameTable[x][y];
}
