#include<stdio.h>
#include<stdlib.h>
#include"helper.h"
#include"heap_SRTF.h"

void SRTF(int**, int*, int);

int main()
{
  int** mat;
  
  printf("Enter the number of processes:");
  int n;
  scanf("%d",&n);
  mat=malloc(n*sizeof(int*));
  
  create(mat,n);
   
  int* heap=malloc(n*sizeof(int));
  SRTF(mat,heap,n);
  printOP(mat,n);
}

void SRTF(int** mat, int* heap, int n)
{
  int CT_k=0, count=0, X=0;
  int min;
  
  while(count<n)
  {
    addnode(heap,count,mat);
    CT_k=AT(count);
    X++;
    
    while(heap_k>=0)
    {
      min=ExtractMin(heap,mat);
      
      if(X<n && AT(X)<=CT_k+BT_L(min))
      { 
        BT_L(min)=BT_L(min)-(AT(X)-CT_k);
        CT_k=AT(X);
        addnode(heap,X,mat);
        X++;
        
        if(BT_L(min)==0)
        {
          CT(min)=CT_k;
          count++;
        }
        else
        addnode(heap,min,mat);
      }
      
      else
      {
        CT(min)=CT_k+=BT_L(min);
        count++;
      }
    }
  }
}
