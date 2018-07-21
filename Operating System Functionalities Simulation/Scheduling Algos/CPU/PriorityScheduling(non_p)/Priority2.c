#include<stdio.h>
#include<stdlib.h>

#define AT(x) mat[x][0]
#define BT(x) mat[x][1]
#define CT(x) mat[x][2]
#define TAT(x) mat[x][3]
#define WT(x) mat[x][4]
#define PTY(x) mat[x][5]

int*q;
int** mat;
int fr,rr=-1;

void sort(int**,int);
void enq(int);
int deq();
void sortq();
void SJF(int**, int);
void printq();

int main()
{
  printf("Enter the no. of processes:");
  int n;
  scanf("%d",&n);

  mat=malloc(n*sizeof(int*));
  q=malloc(n*sizeof(int));

  int i;
  for(i=0;i<n;i++)
  {
    mat[i]=malloc(6*sizeof(int));
    printf("\nEnter the AT,BT and PTY of process %d:",i+1);
    scanf("%d%d%d",&AT(i),&BT(i),&PTY(i));
  }

  sort(mat,n);
  SJF(mat,n);
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
  if(PTY(q[i])<PTY(q[i+1]))
  {
    temp=q[i];
    q[i]=q[i+1];
    q[i+1]=temp;
  }
}

void SJF(int** mat, int n)
{
  int count=0,ctk;
  while(count<n)
  {
    enq(count);
    ctk=AT(count);

    while(fr<=rr)
    {
      int min=deq();
      ctk+=BT(min);

      CT(min)=ctk;
      TAT(min)=CT(min)-AT(min);
      WT(min)=TAT(min)-BT(min);
      count++;

      printf("%d %d\n",min+1,ctk);

      int j;
      for(j=min;j<n;j++)
      if(AT(j)>ctk-BT(min) && AT(j)<=ctk)
      enq(j);

      sortq();
    }
  }

}
