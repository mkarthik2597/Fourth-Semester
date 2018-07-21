#include<stdio.h>
#include<stdlib.h>
#include"helper.h"

void FCFS(int**, int);

int main()
{
  int** mat;
  
  printf("Enter the number of processes:");
  int n;
  scanf("%d",&n);
  mat=malloc(n*sizeof(int*));
  
  create(mat,n);
    
  FCFS(mat,n);
  printOP(mat,n);
}

void FCFS(int** mat, int n)
{
  CT(0)=AT(0)+BT(0);
  int CT_k=CT(0);
 
  int i;
  for(i=1;i<n;i++)
  {
    if(AT(i)<=CT_k)
    CT(i)=CT_k+=BT(i);
    else
    CT_k=CT(i)=AT(i)+BT(i);
  }
}
    
