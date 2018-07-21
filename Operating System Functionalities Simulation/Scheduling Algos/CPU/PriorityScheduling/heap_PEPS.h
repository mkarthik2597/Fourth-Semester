#include<stdio.h>
int heap_k=-1;

void addnode(int*,int,int**);
int ExtractMin(int*, int**);
void adjust_heap(int*, int**);

void addnode(int* heap, int node, int** mat)
{
  heap_k++;
  int child=heap_k;
  int parent=(child-1)/2;
  
  while(child>0 && PTY(heap[parent])<PTY(node))
  {
    heap[child]=heap[parent];
    child=parent;
    parent=(child-1)/2;
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
      if(PTY(heap[i+1])>PTY(heap[i]))
      i++;
    }
    
    if(PTY(node)<PTY(heap[i]))
    {
      heap[parent]=heap[i];
      parent=i;
      i=2*parent+1;
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
