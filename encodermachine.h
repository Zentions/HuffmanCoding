#ifndef ENCODERMACHINE_H
#define ENCODERMACHINE_H
#include<iostream>
#include<string.h>
#include<QFile>
#include "huffmantree.h"
using namespace std;

class EncoderMachine
{
private:
    QString originalText;
    TreeNode *table;
    int textNum;
    int maxNum;
    HuffmanTree *tree;
    QFile *file;
public:
    EncoderMachine(QString text,int sz);
    void NodeFrequency();//统计字频
    void calculateCode(TreeNode *x,string code);//计算编码
    int InOrder(TreeNode *r,int i = 0);//记录编码
    string encode();
    string make();
    void start();
    void writeCodeText();
    void writeTree();
    int *getWeght();//返回权值信息
    int getNum(){return textNum;}//返回节点个数
};

#endif // ENCODERMACHINE_H
