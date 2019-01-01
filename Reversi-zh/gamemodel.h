#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <QWidget>

class GameModel : public QObject
{
    Q_OBJECT

public:

    enum Field { Empty, White, Black, None };
    Field getField(int x, int y);
    int getEmptys();

    GameModel(int size = 4);

    void newGame(int size = 4);
    void setPoint(int x, int y);
    void checkStep();

private:

    Field** gameTable;
    int tableSize;
    int cantSet;
    Field current;

    bool checkPlace(int x, int y);

signals:

    void invalidSet();
    void changePlayer();
    void gameOver();

public slots:
};

#endif // GAMEMODEL_H
