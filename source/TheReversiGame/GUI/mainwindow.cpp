#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    GameBoard(0),
    NewGame(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *evt)
{
    if((GameBoard)&&evt->type()==QEvent::MouseButtonPress)
    {
        qDebug()<<"Click";
        QMouseEvent *me = (QMouseEvent*)evt;
        if(me->button()==Qt::LeftButton)
        {
            x=me->x()/Xb;
            y=me->y()/Xb;
            qDebug()<<x<<y;
            qDebug()<<"Clack";
            TheGame();
        }
    }
    return QMainWindow::eventFilter(obj,evt);
}

void MainWindow::TheGame()
{
    qDebug()<<"Game";
    if (NewGame->Check()==0)
        GamS = EndGame;

    switch (GamS)
    {
    case Player1:
    {
        qDebug()<<"Player1";
        ui->frame->update();
        if (!(NewGame->CheckPlayerGo(GamS)))
        {
            QMessageBox::information(0, "Смена игрока", "Нет Возможных ходов!");
            GamS = Player2;
            ui->label->setText("Ход Игрока 2");
            break;
        }
        if (NewGame->CheckAndGo(Player1, x , y , false))
        {
            GamS = Player2;
            ui->label->setText("Ход Игрока 2");
        }
        ui->label_3->setNum(GameBoard->BlackCount());
        ui->label_5->setNum(GameBoard->WhiteCount());
        break;
    }

    case Player2:
        qDebug()<<"Player2";
        ui->frame->update();
        if (!(NewGame->CheckPlayerGo(GamS)))
        {
            QMessageBox::information(0, "Смена игрока", "Нет Возможных ходов!");
            GamS = Player1;
            ui->label->setText("Ход Игрока 1");
            break;
        }
        if (NewGame->CheckAndGo(Player2, x, y, false))
        {
            ui->label->setText("Ход Игрока 1");
            GamS = Player1;
            ui->label_3->setNum(GameBoard->BlackCount());
            ui->label_5->setNum(GameBoard->WhiteCount());
        }
        break;
    case EndGame:
        if ((GameBoard->BlackCount()) > (GameBoard->WhiteCount()))
            QMessageBox::information(0, "Игра окончена.", "Игрок 1 победил!");
        else if ((GameBoard->BlackCount()) < (GameBoard->WhiteCount()))
            QMessageBox::information(0, "Игра окончена.", "Игрок 2 победил!");
        else
            QMessageBox::information(0, "Игра окончена.", "Ничья!");
        break;
    default:
        break;
    }
}

void MainWindow::on_actionExit_triggered()
{
     QCoreApplication::exit(1);
}

void MainWindow::on_actionNew_Game_triggered()
{
    delete GameBoard;
    GameBoard= new Board;
    delete NewGame;
    NewGame =new Game(GameBoard);
    ui->frame->setBoard(GameBoard);
    GamS=Player1;
    ui->label->setText("Ход Игрока 1");
    ui->label_3->setNum(GameBoard->BlackCount());
    ui->label_5->setNum(GameBoard->WhiteCount());
}

