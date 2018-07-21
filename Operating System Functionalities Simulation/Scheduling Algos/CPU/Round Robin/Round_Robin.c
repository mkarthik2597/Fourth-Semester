#include<stdio.h>
#include<stdlib.h>
#include"helper.h"
#include"queue.h"

int TQ;
void RoundRobin(int**, Q*, int);

int main()
{
  int** mat;
  printf("Enter the number of processes:");
  int n;
  scanf("%d",&n);
  mat=malloc(n*sizeof(int*));
  
  create(mat,n);
  
  printf("Enter the time quantum of your process:");
  scanf("%d",&TQ);
  
  Q q1;
  initQ(&q1,n);
  
  
  RoundRobin(mat,&q1,n);
  printOP(mat,n);
}

void RoundRobin(int** mat, Q* q_ptr, int n)
{
  int count=0;
  int x,prev,j;
  int CT_k;
  
  while(count<n)
  {
    enq(q_ptr,count);
    CT_k=AT(count);
    
    while(Q_COUNT!=0)
    {
      x=deq(q_ptr);
      prev=CT_k;
      
      if(BT_L(x)<=TQ)
      {
        CT(x)=CT_k+=BT_L(x);
        BT_L(x)=0;
        count++;
      }
      else
      {
        CT_k+=TQ;
        BT_L(x)-=TQ;
      }
      
      for(j=0;j<n;j++)
      {
        if(AT(j)>prev && AT(j)<=CT_k)
        enq(q_ptr,j);
      }
      
      if(BT_L(x)!=0)
      enq(q_ptr,x);
    }
  }
}

