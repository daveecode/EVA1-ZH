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
    cantSet = 0;

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

bool GameModel::checkPlace(int x, int y)
{
    if(getField(x+1,y) == (Field)(current % 2 + 1) && getField(x+2,y) == current) {

        cantSet = 0;
        return true;
    }

    else if(getField(x-1,y) == (Field)(current % 2 + 1) && getField(x-2,y) == current) {

        cantSet = 0;
        return true;
    }

    else if(getField(x,y+1) == (Field)(current % 2 + 1) && getField(x,y+2) == current) {

        cantSet = 0;
        return true;
    }

    else if(getField(x,y-1) == (Field)(current % 2 + 1) && getField(x,y-2) == current) {

        cantSet = 0;
        return true;
    }

    else if(getField(x-1,y+1) == (Field)(current % 2 + 1) && getField(x-2,y+2) == current) {

        cantSet = 0;
        return true;
    }

    else if(getField(x+1,y-1) == (Field)(current % 2 + 1) && getField(x+2,y-2) == current) {

        cantSet = 0;
        return true;
    }

    else {

        return false;
    }
}

void GameModel::checkStep()
{
    int sum = 0;
    int emp = getEmptys();

    for(int i = 0; i < tableSize; ++i) {

        for(int j = 0; j < tableSize; ++j) {

            if(getField(i,j) == GameModel::Empty && checkPlace(i,j) == false) {

                ++sum;

                if(sum == emp) {

                    current = (Field)(current % 2 + 1);
                    ++cantSet;

                    if(cantSet == 2) {

                        gameOver();
                        return;
                    }

                    changePlayer();
                }
            }
        }
    }
}

void GameModel::setPoint(int x, int y)
{

    if(getField(x+1,y) == (Field)(current % 2 + 1) && getField(x+2,y) == current) {

        gameTable[x][y] = current;
        gameTable[x+1][y] = current;
        current = (Field)(current % 2 + 1);
    }

    else if(getField(x-1,y) == (Field)(current % 2 + 1) && getField(x-2,y) == current) {

        gameTable[x][y] = current;
        gameTable[x-1][y] = current;
        current = (Field)(current % 2 + 1);
    }

    else if(getField(x,y+1) == (Field)(current % 2 + 1) && getField(x,y+2) == current) {

        gameTable[x][y] = current;
        gameTable[x][y+1] = current;
        current = (Field)(current % 2 + 1);

    }

    else if(getField(x,y-1) == (Field)(current % 2 + 1) && getField(x,y-2) == current) {

        gameTable[x][y] = current;
        gameTable[x][y-1] = current;
        current = (Field)(current % 2 + 1);
    }

    else if(getField(x-1,y+1) == (Field)(current % 2 + 1) && getField(x-2,y+2) == current) {

        gameTable[x][y] = current;
        gameTable[x-1][y+1] = current;
        current = (Field)(current % 2 + 1);
    }

    else if(getField(x+1,y-1) == (Field)(current % 2 + 1) && getField(x+2,y-2) == current) {

        gameTable[x][y] = current;
        gameTable[x+1][y-1] = current;
        current = (Field)(current % 2 + 1);
    }


    else {

        invalidSet();
    }


}

int GameModel::getEmptys()
{
    int value = 0;

    for(int i = 0; i < tableSize; ++i) {

        for(int j = 0; j < tableSize; ++j) {

            if(getField(i,j) == GameModel::Empty) {

                ++value;
            }
        }
    }

    return value;
}

GameModel::Field GameModel::getField(int x, int y)
{
    if(x < 0 || y < 0 || x >= tableSize || y >= tableSize) {

        return GameModel::None;
    }

    return gameTable[x][y];
}
