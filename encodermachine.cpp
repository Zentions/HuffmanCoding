#include "encodermachine.h"
#include<sstream>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>

EncoderMachine::EncoderMachine(QString text,int sz)
{
   originalText = text;
   maxNum = sz;
   table = new TreeNode[maxNum];
   textNum = 0;
   tree = new HuffmanTree(0);
}
void EncoderMachine::NodeFrequency()
{
   string text = originalText.toStdString();
   int i;
   for(i=0;i<text.length();i++)
   {
       int j;
       for(j=0;j<textNum;j++)
       {
           if(text[i]==table[j].ch)
           {
               table[j].weight++;
               break;
           }

       }
       if(j==textNum)
       {
           if(textNum==maxNum)exit(1);
           table[j] = TreeNode(1);
           table[j].ch = text[i];
           textNum++;
       }
   }
}
void EncoderMachine::calculateCode(TreeNode *x,string code)
{
    if(x->leftChild==NULL && x->rightChild ==NULL) x->code = code;
    else
    {
        calculateCode(x->leftChild,code+"0");
        calculateCode(x->rightChild,code+"1");
    }
}
int EncoderMachine::InOrder(TreeNode *r,int i)
{
    if(r->leftChild==NULL && r->rightChild ==NULL)
    {
        table[i++] = *r;
        return i;
    }
    else
    {
       int j = InOrder(r->leftChild,i);
       return InOrder(r->rightChild,j);
   }
}
string EncoderMachine::make()
{
    string text = originalText.toStdString();
    string codeText = "";
    for(int i = 0;i<text.length();i++)
    {
        for(int j =0;j<textNum;j++)
        {
            if(text[i]==table[j].ch) {codeText+=table[j].code;break;}
        }
    }
    return codeText;
}
string EncoderMachine::encode()
{
    int n =textNum;
    string text="";
    for(int i=0;i<n;i++)
    {
        text+=table[i].ch;
        text+="字频->";
        stringstream ss;
        ss<<table[i].weight;
        text+=ss.str();
        text += ("编码->"+table[i].code+"\n");
    }
    return text;
}
void EncoderMachine::start()
{
    NodeFrequency();
    tree->setNum(textNum);
    tree->createTree(table);
    calculateCode(tree->getRoot(),"");
    InOrder(tree->getRoot(),0);
    writeCodeText();
    writeTree();
}
void EncoderMachine::writeCodeText()
{
    QFile file(QString::fromStdString("./codeText.txt"));
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text))
    {
        std::cout<<"操作文件失败"<<std::endl;
    }
    QTextStream in(&file);
    string t = make();
    in<<QString::fromStdString(t);
    file.close();
}
void EncoderMachine::writeTree()
{
    QFile file(QString::fromStdString("./TreeText.txt"));
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text))
    {
        std::cout<<"操作文件失败"<<std::endl;
    }
    QTextStream in(&file);
    QString t = tree->PreorderSequence(tree->getRoot(),"");
    in<<t;
    file.close();
}
