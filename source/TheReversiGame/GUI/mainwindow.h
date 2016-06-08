#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "graffield.h"
#include "Board.h"
#include "State.h"
namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Game *NewGame;
    Board *GameBoard;

public:
    explicit MainWindow(QWidget *parent = 0);
   // Game* NewGame;
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionNew_Game_triggered();

private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject *, QEvent *);
    static const int Xb=60;
    int x,y;
    void TheGame();
    GameState GamS;
};

#endif // MAINWINDOW_H
