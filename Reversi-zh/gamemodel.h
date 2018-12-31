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

    GameModel(int size = 4);

    void newGame(int size = 4);
    void setPoint(int x, int y);

private:

    Field** gameTable;
    int tableSize;
    Field current;

signals:

    void invalidSet();

public slots:
};

#endif // GAMEMODEL_H
