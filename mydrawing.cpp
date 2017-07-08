#include "mydrawing.h"
#include "ui_mydrawing.h"

MyDrawing::MyDrawing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyDrawing)
{
    ui->setupUi(this);
}

MyDrawing::~MyDrawing()
{
    delete ui;
}
void MyDrawing::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(QPoint(4,4),QPoint(500,50));
    QPen pen(Qt::green,3,Qt::DashDotLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(pen);
    QRectF rec(70,40,80,60);
    int start = 30*16;
    int span = 120*16;
    painter.drawArc(rec,start,span);
}
