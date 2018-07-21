#include<stdio.h>
#include<stdlib.h>

#define AT(x) mat[x][0]
#define BT(x) mat[x][1]
#define CT(x) mat[x][2]
#define TAT(x) mat[x][3]
#define WT(x) mat[x][4]
#define PTY(x) mat[x][5]
#define BT_L(x) mat[x][6]

void create(int**,int);

void printOP(int**, int);
void PrintTAT(int**, int);
void PrintWT(int**, int);
void PrintCT(int**, int);

void print(int**, int);
void sort(int**, int);

void create(int** mat, int n)
{

  int i;
  
  for(i=0;i<n;i++)
  mat[i]=malloc(7*sizeof(int));
  
  printf("Enter 1 if processes have priority, else 0: ");
  int pty;
  scanf("%d",&pty);
  
  if(pty==0)
  {  
   printf("\nEnter the AT and BT for each process:\n");
  
   for(i=0;i<n;i++)
   {
     printf("%d: ",i+1);
     scanf("%d%d",&AT(i),&BT(i));
     PTY(i)=1;
     BT_L(i)=BT(i);
   }
   
  }
  
  else
  {
   printf("\nEnter the AT,BT and priority for each process:\n");
  
   for(i=0;i<n;i++)
   {
     printf("%d: ",i+1);
     scanf("%d%d%d",&AT(i),&BT(i),&PTY(i));
     BT_L(i)=BT(i);
   }
  }
   
  sort(mat,n);
  printf("The sorted requests are(AT,BT,BT_L):\n");
  print(mat,n);

}

void printOP(int** mat, int n)
{
  printf("\nCompletion time:\n");
  PrintCT(mat,n);
  printf("\nTurnaround time:\n");
  PrintTAT(mat,n);
  printf("\nWaiting time:\n");
  PrintWT(mat,n);
}

void PrintTAT(int** mat, int n)
{
  int i,sum=0;
  for(i=0;i<n;i++)
  {
    TAT(i)=CT(i)-AT(i);
    printf("%d %d\n",i+1,TAT(i));
    sum+=TAT(i);
  }
  
  printf("\nAverage TAT=%f\n",(float)sum/n);
}

void PrintWT(int** mat, int n)
{
  int i,sum=0;
  for(i=0;i<n;i++)
  {
    WT(i)=TAT(i)-BT(i);
    printf("%d %d\n",i+1,WT(i));
    sum+=WT(i);
  }
  
  printf("\nAverage WT=%f\n", (float)sum/n);
}

void PrintCT(int** mat, int n)
{
  int i;
  for(i=0;i<n;i++)
  printf("%d %d\n",i+1,CT(i));
}

void print(int** mat, int n)
{
  int i;
  for(i=0;i<n;i++)
  printf("%d %d %d\n",AT(i),BT(i),BT_L(i));
}


void sort(int** mat, int size)
{
  int pass,i;
  int* temp;
  
  for(pass=0;pass<size-1;pass++)
  for(i=0;i<size-pass-1;i++)
  if(AT(i)>AT(i+1))
  {
    temp=mat[i];
    mat[i]=mat[i+1];
    mat[i+1]=temp;
  }
}
  
  
