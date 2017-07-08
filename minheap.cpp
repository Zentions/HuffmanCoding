#include "minheap.h"

MinHeap::MinHeap(int sz)
{
   maxSize = sz;
   heap = new TreeNode[maxSize];
   if(heap== NULL)
   {
       std::cout<<"分配失败";
       exit(1);
   }
   currentSize = 0;
}
void MinHeap::siftDown(int start,int m)
{
   int i = start;
   int j = 2*i+1;
   TreeNode temp = heap[i];
   while(j<=m)
   {
       if(j<m && heap[j].weight>heap[j+1].weight)j++;
       if(temp.weight<heap[j].weight)break;
       else
       {
           heap[i] = heap[j];
           i = j;
           j = 2*j+1;

       }
   }
   heap[i] = temp;
}
void MinHeap::siftUp(int start)
{
   int j = start;
   int i = (j-1)/2;
   TreeNode temp = heap[j];
   while(j>0)
   {
       if(heap[i].weight<temp.weight) break;
       else
       {
           heap[j] = heap[i];
           j = i;
           i = (j-1)/2;
       }
   }
   heap[j] = temp;
}
bool MinHeap::insert(TreeNode x)
{
    if(currentSize==maxSize)
    {
        std::cout<<"Heap full";
        return false;
    }
    heap[currentSize++] = x;
    siftUp(currentSize-1);
    return true;
}
TreeNode MinHeap::removeMin()
{

    if(!currentSize)
    {
        std::cout<<"Heap empty";
        exit(1);
    }
    TreeNode x = heap[0];
    heap[0] = heap[currentSize-1];
    currentSize--;
    siftDown(0,currentSize-1);
    return x;
}
