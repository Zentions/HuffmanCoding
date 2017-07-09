#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "minheap.h"
#include <QString>

struct TreeNode
{
    int weight;
    char ch;
    TreeNode *leftChild;
    TreeNode *rightChild;
    string code;
public:

    TreeNode()
    {
        leftChild = NULL;
        rightChild = NULL;
        code = "";
    }
    TreeNode(int weight,TreeNode *leftChild =NULL,TreeNode *rightChild =NULL,char ch = '$')
    {
        this->weight = weight;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
        this->ch = ch;
        code = "";
    }
    TreeNode(const TreeNode& a)
    {
       this->weight = a.weight;
       this->ch  = a.ch;
       this->code = a.code;
       this->leftChild = a.leftChild;
       this->rightChild = a.rightChild;
    }
    bool operator<(TreeNode node){return weight<node.weight;}
    bool operator>(TreeNode node){return weight>node.weight;}
};


class HuffmanTree
{
private:
    int Num;
    TreeNode *root;

public:
    HuffmanTree(int size);
    ~HuffmanTree()
    {delete root;}
    TreeNode *getRoot(){return root;}
    int getNum(){return Num;}
    void deleteTree(TreeNode *t);//删除树
    TreeNode* mergeTree(TreeNode *h1,TreeNode *h2);//合并两棵树
    void createTree(TreeNode *table);//根据字频生成哈夫曼树
    void setNum(int num){Num = num;}
    QString PreorderSequence(TreeNode *r,QString s);
    int create(string s,int i,TreeNode*& r);
    void createTree(string s,int i);
};

#endif // HUFFMANTREE_H
