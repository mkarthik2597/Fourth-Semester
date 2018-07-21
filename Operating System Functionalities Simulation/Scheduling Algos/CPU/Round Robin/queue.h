#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  int* arr;
  int front,rear;
  int count;
  int size;
}Q;

#define Q_REAR q_ptr->rear
#define Q_FRONT q_ptr->front
#define Q_SIZE q_ptr->size
#define Q_COUNT q_ptr->count
#define Q_ARR q_ptr->arr

void enq(Q*,int);
int deq(Q*);
void initQ(Q*,int);
void display(Q*);

void enq(Q* q_ptr, int x)
{
  Q_REAR=(Q_REAR+1)%Q_SIZE;
  Q_COUNT++;
  Q_ARR[Q_REAR]=x;
}

int deq(Q* q_ptr)
{
  int temp=Q_ARR[Q_FRONT];
  Q_COUNT--;
  Q_FRONT=(Q_FRONT+1)%Q_SIZE;
  return temp;
}

void initQ(Q* q_ptr, int size)
{
  Q_SIZE=size;
  Q_ARR=malloc(Q_SIZE*sizeof(int));
  Q_FRONT=0;
  Q_REAR=-1;
  Q_COUNT=0;
}

void displayQ(Q* q_ptr)
{
  int i;
  int temp=Q_FRONT;
  
  for(i=0;i<Q_COUNT;i++)
  {
    printf("%d ",Q_ARR[temp]);
    temp=(temp+1)%Q_SIZE;
  }
  
  printf("\n");
}

