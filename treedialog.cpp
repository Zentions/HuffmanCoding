#include "treedialog.h"
#include "ui_treedialog.h"
#include <QPropertyAnimation>
#include <QDebug>
TreeDialog::TreeDialog(int *weight,int num,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TreeDialog)
{
    ui->setupUi(this);
    treeScene = new TreeScene(weight,num);
   ui->graphicsView->setScene(treeScene);
 //  connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Next()));





//    //非正式
//    scene= new QGraphicsScene(this);
//    ui->graphicsView->setScene(scene);
//    item = new NodeItem("rr");
//    item->setColor(Qt::green);
//   // scene->addItem(item);
//    item->setPos(0,0);
//    item1 = new NodeItem("rr");
//    item1->setColor(Qt::green);
//    scene->addItem(item1);
//    item1->setPos(-30,51.9);
//    item3 = new NodeItem("rr");
//    item3->setColor(Qt::green);
//    scene->addItem(item3);
//    item3->setPos(30,51.9);
//    QGraphicsLineItem *line1 = new QGraphicsLineItem(15,15,-15,66.9);
//    QGraphicsLineItem *line2 = new QGraphicsLineItem(15,15,45,66.9);
//    line1->setPen(QPen(Qt::green));
//    line2->setPen(QPen(Qt::green));
//    //scene->addItem(line1);
//    scene->addItem(line2);
//    QLineF f = line1->line();
//    cout<<f.x2()<<" "<<f.y2()<<endl;
//    ui->graphicsView->setBackgroundBrush(QColor(5,255,255,100));
//    QGraphicsItemGroup *group = new QGraphicsItemGroup;
//    group->addToGroup(item);
//    group->addToGroup(line1);
//    group->setFlag(QGraphicsItem::ItemIsMovable);
//    scene->addItem(group);

}

TreeDialog::~TreeDialog()
{
    delete ui;
}
void TreeDialog::Next()
{

    treeScene->createTree();
}





void TreeDialog::on_pushButton_clicked()
{
    Next();
}
