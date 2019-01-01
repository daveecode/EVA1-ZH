#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QLayout>
#include "gamemodel.h"

class GameWidget : public QWidget
{
    Q_OBJECT

public:

    GameWidget(QWidget *parent = 0);
    ~GameWidget();

private:

    QVector<QVector<QPushButton*>> fields;
    QGridLayout *grid;

    GameModel* model;

    void newGame(int size = 4);
    void drawTable();
    int gameSize;

private slots:

    void click();
    void model_invalidSet();
    void model_changePLayer();
    void model_gameOver();
};

#endif // GAMEWIDGET_H
