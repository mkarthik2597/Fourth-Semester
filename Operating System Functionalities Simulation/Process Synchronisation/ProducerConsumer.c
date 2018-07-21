#include<stdio.h>
#include<stdlib.h>

#define TYPE(i) mat[i][0]
#define AT(i) mat[i][1]
#define item(i) mat[i][2]
#define num(i) mat[i][3]
#define WAIT(i) mat[i][4]

#define PROD 0
#define CONS 1

void enq(int);
int deq();
void produce(int**,int);
void consume(int**,int);
void ProdCons(int**);

int* Q;
int fr,rr=-1,count;
int size;
int n;

int producerWT,consumerWT;

int main()
{
  printf("Enter buffer size:");
  scanf("%d",&size);

  Q=malloc(size*sizeof(int));
  printf("Enter total no. of producers and consumers:");
  scanf("%d",&n);
  int** mat=malloc(n*sizeof(int*));
  int i;
  for(i=0;i<n;i++)
  {
    mat[i]=malloc(5*sizeof(int));
    printf("Enter P/C, P/C no, item(if P) and AT:");
    char pc;
    scanf(" %c",&pc);

    if(pc=='P')
    {
      TYPE(i)=PROD;
      scanf("%d%d%d",&num(i),&item(i),&AT(i));
    }
    else
    {
      TYPE(i)=CONS;
      scanf("%d%d",&num(i),&AT(i));
      item(i)=-1;
    }

    WAIT(i)=0;
  }

  ProdCons(mat);
}

void enq(int x)
{
  rr=(rr+1)%size;
  Q[rr]=x;
  count++;
}

int deq()
{
  int temp=Q[fr];
  fr=(fr+1)%size;
  count--;
  return temp;
}

void ProdCons(int** mat)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(TYPE(i)==PROD)
    {
      if(count!=n)
      {
        printf("Producer %d produces %d at time %d\n",num(i),item(i),AT(i));
        enq(item(i));

        if(consumerWT>0)
        consume(mat,AT(i));
      }
      else
      {
        printf("Buffer is full.Producer %d is under wait\n",num(i));
        producerWT++;
        WAIT(i)=1;
      }
    }

    else
    {
      if(count!=0)
      {
        int x=deq();
        printf("Consumer %d consumes %d at time %d\n",num(i),x,AT(i));

        if(producerWT>0)
        produce(mat,AT(i));
      }
      else
      {
        printf("Buffer is empty.Consumer %d is under wait\n",num(i));
        consumerWT++;
        WAIT(i)=1;
      }
    }
  }
}

void consume(int** mat,int at)
{
  int x=deq();
  int i;
  for(i=0;i<n;i++)
  {
    if(TYPE(i)==CONS && WAIT(i)==1)
    printf("Consumer %d consumes %d at time %d\n",num(i),x,at);
    break;
  }
  consumerWT--;
}

void produce(int** mat,int at)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(TYPE(i)==PROD && WAIT(i)==1)
    printf("Producer %d produces %d at time %d\n",num(i),item(i),at);
    enq(item(i));

    break;
  }
  producerWT--;
}
