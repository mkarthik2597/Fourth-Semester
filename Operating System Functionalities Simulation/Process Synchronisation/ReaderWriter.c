#include<stdio.h>
#include<stdlib.h>

#define RW(i) mat[i][0]
#define AT(i) mat[i][1]
#define BT(i) mat[i][2]

#define RDR 0
#define WR 1

int main()
{
  printf("Enter total no. of reader/writers:");
  int n;
  scanf("%d",&n);

  int** mat=malloc(n*sizeof(int*));
  int i;
  for(i=0;i<n;i++)
  {
    mat[i]=malloc(3*sizeof(int));
    printf("Enter reader/writer(0,1), AT and BT:");
    scanf(" %c%d%d",&RW(i),&AT(i),&BT(i));
  }

  Algo(mat,n);
}

void Algo(int** mat,int n)
{

}
