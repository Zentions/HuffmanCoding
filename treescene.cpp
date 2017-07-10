#include "treescene.h"
#include "minheap.cpp"
TreeScene::TreeScene(int *weight,int num)
{
  this->num = num;
  unVis = 0;
  int n = -num*90;
  for(int i=0;i<num;i++)
  {
      NodeItem *item = new  NodeItem(QString::number(weight[i]));
      vec.append(item);
      item->setPosition(n+90*i,90);
      addItem(item);

  }
}
NodeItem* TreeScene::findMin()
{
    NodeItem *item;
    int i;
    for(i=0;i<vec.size();i++)
    {
        if(!vec.at(i)->isVisited())
        {
            item = vec.at(i);
            break;
        }
    }
    if(i>=vec.size())return NULL;
    for(i=0;i<vec.size();i++)
    {
        int a = vec.at(i)->text.toInt();
        int b = item->text.toInt();
        if(a<b && !vec.at(i)->isVisited()) item = vec.at(i);
    }
    item->setVisit(true);
    item->setColor(Qt::red);
    item->update();
    return item;
}
void TreeScene::createTree()
{
    if(unVis>=num-1)return;
    unVis++;
    NodeItem *first = findMin();
    NodeItem *second = findMin();
    QString num1 = QString::number(first->text.toInt()+second->text.toInt());
    NodeItem *parent = new NodeItem(num1,first,second);
    parent->setPosition(first->getPosition().rx(),first->getPosition().ry()-40);
    addItem(parent);
    move(first,second,parent);
    vec.append(parent);
}
void TreeScene::move(NodeItem *first,NodeItem *second,NodeItem *parent)
{

    qreal x1 = first->getPosition().rx(), y1=first->getPosition().ry();
    qreal x2 = second->getPosition().x(), y2=second->getPosition().ry();
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    QPropertyAnimation *animation=setNodeAnimation(parent,x1,y1-40,x1,y1);
    moveTree(first,x1,y1,x1-30,y1+51.9,group);
    moveTree(second,x2,y2,x1+30,y1+51.9,group);
    group->addAnimation(animation);
    group->start(QAbstractAnimation::DeleteWhenStopped);
    QGraphicsLineItem *left = new QGraphicsLineItem(QLineF(x1+15,y1+15,x1-15,y1+66.9));
    QGraphicsLineItem *right = new QGraphicsLineItem(QLineF(x1+15,y1+15,x1+45,y1+66.9));
    left->setPen(QPen(Qt::red));
    right->setPen(QPen(Qt::red));
    parent->leftLine = left;
    parent->rightLine = right;
    addItem(left);
    addItem(right);
}
void TreeScene::moveTree(NodeItem *item,qreal x1,qreal y1,qreal x2,qreal y2,QParallelAnimationGroup *group)
{
   QPropertyAnimation *animation = setNodeAnimation(item,x1,y1,x2,y2);
   group->addAnimation(animation);
   if(item->leftNode!=NULL && item->rightNode !=NULL)
   {
       //QPropertyAnimation *animation1 = setLineAnimation(item->leftLine,x2+15,y2+15,x2-15,y2+66.9);
      // QPropertyAnimation *animation2 = setLineAnimation(item->rightLine,x2+15,y2+15,x2+45,y2+66.9);
//       group->addAnimation(animation1);
//       group->addAnimation(animation2);
       moveTree(item->leftNode,x1-30,y1+51.9,x2-30,y2+51.9,group);
       moveTree(item->rightNode,x1+30,y1+51.9,x2+30,y2+51.9,group);
   }
}
QPropertyAnimation *TreeScene::setNodeAnimation(NodeItem *item,qreal x1,qreal y1,qreal x2,qreal y2)
{
    QPropertyAnimation *animation= new QPropertyAnimation(item,"pos");
    animation->setDuration(3000);
    animation->setStartValue(QPointF(x1,y1));
    animation->setEndValue(QPointF(x2,y2));
    return animation;
}
//QPropertyAnimation *TreeScene::setLineAnimation(QGraphicsLineItem *item,qreal x1,qreal y1,qreal x2,qreal y2)
//{
//    QPropertyAnimation *animation= new QPropertyAnimation(item,"pos");
//    animation->setDuration(3000);
//    animation->setStartValue(item->line());
//    animation->setEndValue(QLineF(x1,y1,x2,y2));
//    return animation;
//}
