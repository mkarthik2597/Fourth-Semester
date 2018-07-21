#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define HOLE 1
#define PROCESS 0
typedef struct
{
  int start;
  int end;
  int size;
  int type;
} partition;

partition* memory[30];
int count=0;

int CheckHole(int);
void EmbedProcess(int, int);

int main()
{
  printf("Enter the no of bytes in memory:");
  int FreeSpace;
  scanf("%d",&FreeSpace);

  repeat:
  printf("Enter\n1 to add a process\n2 to swap out a process\n3 to display memory layout\n4 to exit:");
  int i;
  scanf("%d",&i);

  switch(i)
  {
    case 1: printf("Enter required size:");
            int size;
            scanf("%d",&size);
            if(CheckHole(size)==0 && FreeSpace>=size)
            {
              memory[count]=malloc(sizeof(partition));
              if(count==0)
              memory[count]->start=0;
              else
              memory[count]->start=memory[count-1]->end;

              memory[count]->size=size;
              memory[count]->end=memory[count]->start+size;
              memory[count]->type=PROCESS;
              count++;

              FreeSpace-=size;
            }
            break;

    case 2: printf("Enter the memory size that you need to swap out:");
            scanf("%d",&size);

            int ct;
            for(ct=0;ct<count;ct++)
            {
              if(memory[ct]->size==size)
              {
                memory[ct]->type=HOLE;
                break;
              }
            }
            break;

    case 3: for(ct=0;ct<count;ct++)
            printf("(%d,%d) %d %c\n",memory[ct]->start,memory[ct]->end,memory[ct]->size,(memory[ct]->type==HOLE)?'H':'P');

  }
  if(i!=4)
  goto repeat;
}

int CheckHole(int size)
{
  int i;
  int maxIndex=count,maxSize=-INT_MAX;
  for(i=0;i<count;i++)
  {
    if(memory[i]->type==HOLE && memory[i]->size>=size)
    {
      if(memory[i]->size>maxSize)
      {
        maxIndex=i;
        maxSize=memory[i]->size;
      }
    }
  }

  if(maxIndex!=count)
  {
    EmbedProcess(maxIndex,size);
    return 1;
  }
  return 0;
}

void EmbedProcess(int i,int size)
{
  int temp=memory[i]->end;
  memory[i]->end=memory[i]->start+size;
  memory[i]->type=PROCESS;

  if(memory[i]->size>size)
  {
    int j;
    for(j=count-1;j>i;j--)
    memory[j+1]=memory[j];

    memory[i+1]=malloc(sizeof(partition));
    memory[i+1]->start=memory[i]->end;
    memory[i+1]->end=temp;
    memory[i+1]->type=HOLE;
    memory[i+1]->size=memory[i+1]->end-memory[i+1]->start;

    count++;
  }

  memory[i]->size=size;
}
