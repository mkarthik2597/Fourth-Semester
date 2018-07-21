#include<stdio.h>
#include<stdlib.h>
#include"helper.h"
#include"heap_PTY.h"

void Priority(int**, int*, int);

int main()
{
  int** mat;
  
  printf("Enter the number of processes:");
  int n;
  scanf("%d",&n);
  mat=malloc(n*sizeof(int*));
  
  create(mat,n);
  int* heap=malloc(n*sizeof(int));

  Priority(mat,heap,n);
  printOP(mat,n);
}

void Priority(int** mat, int* heap, int n)
{
  int CT_k=0;
  int count=0,j,min;
  
  while(count<n)
  {
    addnode(heap,count,mat);
    CT_k=AT(count);
    
    while(heap_k>=0)
    {
      min=ExtractMin(heap,mat);
      CT_k+=BT(min);
      CT(min)=CT_k;
      count++;
      
      for(j=count;j<n;j++)
      {
        if(AT(j)<=CT_k && AT(j)>(CT_k-BT(min)))
        addnode(heap,j,mat);
      }
    }
  }
}

      
  
