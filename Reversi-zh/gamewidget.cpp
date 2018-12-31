#include "gamewidget.h"
#include <QMessageBox>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    grid = new QGridLayout;
    model = new GameModel;

    newGame();

    connect(model, SIGNAL(invalidSet()), this, SLOT(model_invalidSet()));
}

GameWidget::~GameWidget()
{

}

void GameWidget::newGame(int size)
{

    model->newGame(size);

    gameSize = size;

    for(int i = 0; i < fields.size(); ++i) {

        qDeleteAll(fields[i]);
    }

    fields.resize(size);

    for(int i = 0; i < size; ++i) {

        fields[i].resize(size);

        for(int j = 0; j < size; ++j) {

            fields[i][j] = new QPushButton(this);
            fields[i][j]->setFixedSize(100, 100);
            grid->addWidget(fields[i][j],i,j);
            connect(fields[i][j], SIGNAL(clicked(bool)), this, SLOT(click()));
        }
    }

    setLayout(grid);

    drawTable();
}

void GameWidget::click()
{
    QObject *senderObject = sender();

    QPushButton *senderButton = qobject_cast<QPushButton*>(senderObject);

    for(int i = 0; i < gameSize; ++i) {

        for(int j = 0; j < gameSize; ++j) {

            if(senderButton == fields[i][j]) {

                model->setPoint(i,j);
                drawTable();
            }
        }
    }
}

void GameWidget::model_invalidSet()
{
    QMessageBox::information(this, trUtf8("Érvénytelen lépés!"), trUtf8("Oda nem rakhatsz te unfair bohóc!"));
}

void GameWidget::drawTable()
{
    for(int i = 0; i < gameSize; ++i) {

        for(int j = 0; j < gameSize; ++j) {

            switch(model->getField(i,j)) {

            case GameModel::Black:

                fields[i][j]->setStyleSheet("background-color: black");
                break;

            case GameModel::White:

                fields[i][j]->setStyleSheet("background-color: white");
                break;

            case GameModel::Empty:

                fields[i][j]->setStyleSheet("background-color: grey");
                break;
            }
        }
    }
}
