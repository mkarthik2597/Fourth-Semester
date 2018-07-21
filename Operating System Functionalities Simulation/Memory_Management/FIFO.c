#include<stdio.h>

int main()
{
  printf("Enter the number of frames:");
  int fno;;
  scanf("%d",&fno);
  int frames[fno];
  char status;

  int i;
  for(i=0;i<fno;i++)
  frames[i]=-1;

  printf("Enter the number of pages:");
  int pgno;
  scanf("%d",&pgno);

  int k,x,flag;
  int j=-1;
  int hitct=0;

  printf("Enter the pages:");
  for(i=0;i<pgno;i++)
  {
    int item;
    scanf("%d",&item);
    flag=0;
    for(k=0;k<fno;k++)
    {
      if(frames[k]==item)
      {
        hitct++;
        flag=1;
        status='H';
        break;
      }

      if(frames[k]==-1)
      {
        flag=1;
        frames[k]=item;
        status='M';
        break;
      }
    }
    if(flag==0)
    {
      j=(j+1)%fno;
      frames[j]=item;
      status='M';
    }

    for(k=0;k<fno;k++)
    printf("%3d ",frames[k]);

    printf(" %c",status);
    printf("\n");
  }

  printf("\nHit ratio=%f",(float)hitct/pgno);
  printf("\nMiss ratio=%f\n",1-(float)hitct/pgno);
}
