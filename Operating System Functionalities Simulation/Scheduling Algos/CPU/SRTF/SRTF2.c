#include<stdio.h>
#include<stdlib.h>

#define AT(x) mat[x][0]
#define BT(x) mat[x][1]
#define CT(x) mat[x][2]
#define TAT(x) mat[x][3]
#define WT(x) mat[x][4]
#define PTY(x) mat[x][5]
#define BTL(x) mat[x][6]

int*q;
int** mat;
int fr,rr=-1;

void sort(int**,int);
void enq(int);
int deq();
void sortq();
void SRTF(int**, int);
void printq();

int main()
{
  printf("Enter the no. of processes:");
  int n;
  scanf("%d",&n);

  mat=malloc(n*sizeof(int*));
  q=malloc(100*sizeof(int));

  int i;
  for(i=0;i<n;i++)
  {
    mat[i]=malloc(7*sizeof(int));
    printf("\nEnter the AT,BT of %d:",i+1);
    scanf("%d%d",&AT(i),&BT(i));
    BTL(i)=BT(i);
  }

  sort(mat,n);
  SRTF(mat,n);
}

void sort(int** mat, int size)
{
  int i,pass,*temp;
  for(pass=0;pass<size-1;pass++)
  for(i=0;i<size-pass-1;i++)
  if(AT(i)>AT(i+1))
  {
    temp=mat[i];
    mat[i]=mat[i+1];
    mat[i+1]=temp;
  }
}

void enq(int x)
{
  q[++rr]=x;
}

int deq()
{
  return q[fr++];
}

void sortq()
{
  int pass,i,temp;

  for(pass=fr;pass<rr;pass++)
  for(i=fr;i<rr;i++)
  if(BTL(q[i])>BTL(q[i+1]))
  {
    temp=q[i];
    q[i]=q[i+1];
    q[i+1]=temp;
  }
  else if(BTL(q[i])==BTL(q[i+1]))
  {
    if(AT(q[i])>AT(q[i+1]))
    {
      temp=q[i];
      q[i]=q[i+1];
      q[i+1]=temp;
    }
  }
}

void SRTF(int** mat, int n)
{
  int ctk=0, count=0, X=0;
  int min;

  while(count<n)
  {
    enq(count);
    ctk=AT(count);
    X++;

    while(fr<=rr)
    {
      sortq();
      min=deq();
      printf("%d ",min+1);

      if(X<n && AT(X)<=ctk+BTL(min))
      {
        BTL(min)=BTL(min)-(AT(X)-ctk);
        ctk=AT(X);
        enq(X);
        X++;

        if(BTL(min)==0)
        {
          CT(min)=ctk;
          count++;
        }
        else
        enq(min);
      }

      else
      {
        CT(min)=ctk+=BTL(min);
        count++;
      }
    }
  }
}
