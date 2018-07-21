#include<stdio.h>
int heap_k=-1;

void addnode(int*,int, int**);
int ExtractMin(int*, int**);
void adjust_heap(int*, int**);

void addnode(int* heap, int node, int** mat)
{
  heap_k++;
  int child=heap_k;
  int parent=(child-1)/2;
  
  while(child>0 && BT_L(heap[parent])>BT_L(node))
  {
    heap[child]=heap[parent];
    child=parent;
    parent=(child-1)/2;
  }
  
  if(BT_L(heap[parent])==BT_L(node))
  {
    if(AT(heap[parent])>AT(node))
    {
      heap[child]=heap[parent];
      child=parent;
    }
  }
  
  heap[child]=node;
}

int ExtractMin(int* heap, int** mat)
{
  int temp;
  temp=heap[heap_k];
  heap[heap_k]=heap[0];
  heap[0]=temp;
  
  adjust_heap(heap, mat);
  return heap[heap_k--];
}

void adjust_heap(int* heap, int** mat)
{
  int parent=0,node=heap[parent],i=2*parent+1;
  
  while(i<heap_k)
  { 
    if(i+1<heap_k)
    {
      if(BT_L(heap[i+1])<BT_L(heap[i]))
      i++;
      
      else if(BT_L(heap[i+1])==BT_L(heap[i]))
      {
        if(AT(heap[i+1])<AT(heap[i]))
        i++;
      }
    }
    
    if(BT_L(node)>BT_L(heap[i]))
    {
      heap[parent]=heap[i];
      parent=i;
      i=2*parent+1;
    }
    else if(BT_L(node)==BT_L(heap[i]))
    {
      if(AT(node)>AT(heap[i]))
      {
        heap[parent]=heap[i];
        parent=i;
        i=2*parent+1;
      }
    }
    else
    break;
  }
  heap[parent]=node;
}

void printheap(int* heap)
{
  int i;
  for(i=0;i<=heap_k;i++)
  printf("%d ",heap[i]);
  
  printf("\n");
}
