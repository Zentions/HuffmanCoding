#ifndef MINHEAP_H
#define MINHEAP_H
#include<iostream>
#include<string.h>
using namespace std;
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
};

class MinHeap
{
private:
    int maxSize;
    int currentSize;
    TreeNode *heap;
    void siftDown(int start,int m);//自上而下，从start到m下滑调整为最小堆
    void siftUp(int start);//自下而上，从start上滑调整为最小堆
public:
    MinHeap(int sz=0);
    bool insert(TreeNode);
    TreeNode removeMin();
    bool isEmpty()
    {return currentSize==0;}
    bool isFull()
    {return currentSize==maxSize;}
    void makeEmpty()
    {currentSize=0;}
};

#endif // MINHEAP_H
