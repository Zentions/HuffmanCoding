#include "huffmantree.h"
#include "minheap.cpp"
//记录了完全前序序列，并用它重新构造了哈夫曼树
HuffmanTree::HuffmanTree(int size)
{
   Num = size;
   root = NULL;
}

void HuffmanTree::deleteTree(TreeNode *t)
{
    if(t!=NULL)
    {
        TreeNode *temp = t;
        deleteTree(t->leftChild);
        deleteTree(t->rightChild);
        delete temp;
    }
}
TreeNode* HuffmanTree::mergeTree(TreeNode *h1,TreeNode *h2)
{
    TreeNode *parent = new TreeNode;
    parent->weight = h1->weight+h2->weight;
    parent->leftChild = h1;
    parent->rightChild = h2;
    return parent;
}
void HuffmanTree::createTree(TreeNode *table)
{
    MinHeap<TreeNode> heap(Num+5);
    for(int i = 0;i<Num;i++) heap.insert(table[i]);
    TreeNode* parent;
    TreeNode *first,*second;
    for(int i = 0;i<Num-1;i++)
    {
        first = new TreeNode;
        second = new TreeNode;
        *first = heap.removeMin();
        *second = heap.removeMin();
        parent=mergeTree(first,second);
        heap.insert(*parent);
    }
    root = parent;
}
QString HuffmanTree::PreorderSequence(TreeNode *r,QString s)
{
    if(r->leftChild==NULL && r->rightChild ==NULL)
    {
       s+=r->ch;
       return s;
    }
    else
    {
       s+= "@";
       QString s1 = PreorderSequence(r->leftChild,s);
       return PreorderSequence(r->rightChild,s1);
    }
}
int HuffmanTree::create(string s,int i,TreeNode*& r)
{
    r = new TreeNode(0);
    if(s[i]!='@') {r->ch = s[i];return i+1;}
    else
    {
        r->ch = '@';
        int n= create(s,i+1,r->leftChild);
        int m = create(s,n,r->rightChild);
        return m;
    }
}
void HuffmanTree::createTree(string s,int i)
{
   create(s,i,root);
}
