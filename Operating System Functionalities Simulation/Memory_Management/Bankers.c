#include<stdio.h>
#include<stdlib.h>

int resources;
int processes;

int need_lt_avail(int (*)[resources],int*,int);
void add(int(*)[resources],int*,int);
int SafetyAlgo(int (*need)[resources],int (*allocated)[resources],int* work, int* finish, int* safeseq);


int main()
{
  printf("Enter the number of resources:");
  scanf("%d",&resources);

  int available[resources];
  int work[resources];

  printf("Enter the number of instances of each resource type currently available\n");
  int i;
  for(i=0;i<resources;i++)
  {
    printf("%d:",i+1);
    scanf("%d",&available[i]);
    work[i]=available[i];
  }

  printf("Enter the number of processes:");
  scanf("%d",&processes);

  int finish[processes];
  int safeseq[processes];

  for(i=0;i<processes;i++)
  finish[i]=0;

  int allocated[processes][resources];
  int maxneed[processes][resources];
  int need[processes][resources];

  printf("Enter the number of resources allocated to each process and its maximum need\n");
  int p,r;

  for(p=0;p<processes;p++)
  {
    printf("\nProcess %d:\n\n",p+1);
    for(r=0;r<resources;r++)
    {
      printf("Resource %d:",r+1);
      scanf("%d",&allocated[p][r]);
      scanf("%d",&maxneed[p][r]);

      need[p][r]=maxneed[p][r]-allocated[p][r];
    }
  }

  SafetyAlgo(need,allocated,work,finish,safeseq);

  for(i=0;i<resources;i++)
  {
    finish[i]=0;
    work[i]=available[i];
  }

  int request[resources];
  printf("Enter a process which places a request:");
  int x;
  scanf("%d",&x);

  printf("Enter the no of each resource type requested:");
  for(i=0;i<resources;i++)
  {
    scanf("%d",&request[i]);

    if(need[x][i]<request[i])
    {
      printf("Request for %d exceeds maximum need!\n",i+1);
      exit(0);
    }

    if(available[i]<request[i])
    {
      printf("Request for %d exceeds no of available resources!\n",i+1);
      exit(0);
    }

    work[i]-=request[i];
    allocated[x][i]+=request[i];
    need[x][i]-=request[i];
  }

  if(SafetyAlgo(need,allocated,work,finish,safeseq)==1)
  printf("Request can be granted\n");
  else
  printf("Granting this request will put the system into deadlock!\n");

}

int SafetyAlgo(int (*need)[resources],int (*allocated)[resources],int* work, int* finish, int* safeseq)
{
  int count=0,safect=0;
  int flag,i;

  while(count<processes)
  {
    flag=0;
    for(i=0;i<processes;i++)
    {
      if(finish[i]==0 && need_lt_avail(need,work,i))
      {
        safeseq[safect++]=i+1;
        count++;
        finish[i]=1;
        flag=1;
        add(allocated,work,i);
      }
    }
    if(flag==0)
    {
      printf("System has a deadlock!\n");
      return 0;
    }
  }

  if(safect==processes)
  {
    printf("The safe sequence is:");
    for(i=0;i<safect;i++)
    printf("%d ",safeseq[i]);

    printf("\n");
    return 1;
  }
}

int need_lt_avail(int (*need)[resources], int* work, int p)
{
  int i,k;
  for(i=0;i<resources;i++)
  {
    if(need[p][i]>work[i])
    {
      printf("Need:(");
      for(i=0;i<resources;i++)
      printf("%d,",need[p][i]);
      printf(") ");

      printf("Work:(");
      for(i=0;i<resources;i++)
      printf("%d,",work[i]);
      printf(") ");

      printf("%d skipped\n",p+1);

      return 0;
    }

  }

  printf("Need:(");
  for(i=0;i<resources;i++)
  printf("%d,",need[p][i]);
  printf(") ");

  printf("Work:(");
  for(i=0;i<resources;i++)
  printf("%d,",work[i]);
  printf(") ");

  printf("%d picked\n",p+1);
  return 1;
}

void add(int(*allocated)[resources], int* work, int p)
{
  int i;
  for(i=0;i<resources;i++)
  work[i]+=allocated[p][i];
}
