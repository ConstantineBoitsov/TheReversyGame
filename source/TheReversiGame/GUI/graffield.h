#ifndef GRAFFIELD_H
#define GRAFFIELD_H

#include <QFrame>
#include <QPainter>
#include <QWidget>
#include "Board.h"
#include <QtGui>

namespace Ui
{
class GrafField;
}

class GrafField : public QFrame
{
    Q_OBJECT
    Board *Field;

public:
    explicit GrafField(QWidget *parent = 0);
    ~GrafField();
    void paintEvent(QPaintEvent *);
    void paintBoard(QPainter &painter);
    void setBoard(Board *B);

private:
    Ui::GrafField *ui;
    static const int Xb=60;
};

#endif // GRAFFIELD_H
