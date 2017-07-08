#include "decodemachine.h"
#include <QFile>
#include<QTextStream>
DecodeMachine::DecodeMachine()
{
   tree = new HuffmanTree(1);
   text = "";
}
void DecodeMachine::readTree()
{
    QFile f("./TreeText.txt");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Open failed." << std::endl;
    }
    QTextStream txtInput(&f);
    QString str;
    while(!txtInput.atEnd())
    {
        str += txtInput.readLine();
    }
    f.close();
    tree->createTree(str.toStdString(),0);
    std::cout << str.toStdString() << std::endl;
}
void DecodeMachine::traverse(TreeNode *r)
{
    if(r!=NULL)
    {
        std::cout <<r->ch<<std::endl;
        traverse(r->leftChild);
        traverse(r->rightChild);
    }
}
void DecodeMachine::start()
{
    readTree();
    decode();
    //traverse(tree->getRoot());
}
string DecodeMachine::readCodeText()
{
    QFile f("./codeText.txt");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Open failed." << std::endl;
    }

    QTextStream txtInput(&f);
    QString str;
    while(!txtInput.atEnd())
    {
        str += txtInput.readLine();
    }
    f.close();
    std::cout << str.toStdString() << std::endl;
    return str.toStdString();
}
void DecodeMachine::decode()
{
    string str = readCodeText();
    TreeNode *temp;
    for(int i =0;i<str.length();i++)
    {
        temp = tree->getRoot();
        while(temp->leftChild!=NULL && temp->rightChild!=NULL)
        {
            if(str[i]=='0')temp = temp->leftChild;
            else temp = temp->rightChild;
            i++;
        }
        i--;
        text+=temp->ch;
        std::cout <<temp->ch<< std::endl;
    }
}
