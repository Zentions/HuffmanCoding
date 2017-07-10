#ifndef NODEVIEW_H
#define NODEVIEW_H
#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QGraphicsLineItem>
#include <QGraphicsSceneContextMenuEvent>
#include <iostream>
using namespace std;

class NodeItem : public QGraphicsObject
{
private:
    QPointF point;
    QColor brushColor;
    bool Visited;
protected:
    QRectF boundingRect() const;
    void keyPressEvent(QKeyEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    QString text;
    NodeItem *leftNode;
    NodeItem *rightNode;
    QGraphicsLineItem *leftLine;
    QGraphicsLineItem *rightLine;
    NodeItem(QString text,NodeItem *leftNode=NULL,NodeItem *rightNode = NULL);
    NodeItem(){}
    bool isVisited(){return Visited;}
    void setVisit(bool v){ Visited = v;}
    void setColor(const QColor &color){brushColor = color;}
    void setPosition(qreal ax, qreal ay);
    QPointF getPosition(){return point;}
};

#endif // NODEVIEW_H
