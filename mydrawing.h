#ifndef MYDRAWING_H
#define MYDRAWING_H

#include <QWidget>
#include <QPainter>
namespace Ui {
class MyDrawing;
}

class MyDrawing : public QWidget
{
    Q_OBJECT

public:
    explicit MyDrawing(QWidget *parent = 0);
    ~MyDrawing();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::MyDrawing *ui;
};

#endif // MYDRAWING_H
