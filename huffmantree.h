#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "minheap.h"
#include <QString>
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
