#include "graffield.h"
#include "ui_graffield.h"

void Board::PrintBoard(QPainter &painter)
{
    static const int Xb=60;
    for (int k = 0; k < Bsize; k++) {
        for (int c = 0; c < Bsize; c++){
        if(dots[c][k].GetState()==White)
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        if(dots[c][k].GetState()==Black)
            painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        if(dots[c][k].GetState()!=Empty)
            painter.drawEllipse(c*Xb+5,k*Xb+5,Xb-10,Xb-10);
        }
    }
}

GrafField::GrafField(QWidget *parent) :
    QFrame(parent),
    Field(0),
    ui(new Ui::GrafField)
{
    ui->setupUi(this);
}

GrafField::~GrafField()
{
    delete ui;
}

void GrafField::setBoard(Board *B)
{
    Field=B;
    update();
}

void GrafField::paintEvent(QPaintEvent *)
{
    if(!Field)
        return;
    QPainter painter(this);
    paintBoard(painter);
    Field->PrintBoard(painter);
}

void GrafField::paintBoard(QPainter &painter)
{
    painter.setPen(Qt::black);
    painter.fillRect(0,0,Xb*8,Xb*8, Qt::darkCyan);
    for(int i=0;i<=Xb*8;i+=Xb)
    {
        painter.drawLine(i, 0, i, Xb*8);
        painter.drawLine(0,i,Xb*8,i);
    }
}
