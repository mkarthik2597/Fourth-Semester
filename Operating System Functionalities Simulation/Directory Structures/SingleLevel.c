#include<stdio.h>
#include<stdlib.h>

#define FOLDER 0
#define FILE 1

struct node
{
  char name[20];
  int type;
  struct node** child;
};
typedef struct node node;

int main()
{
  printf("Enter Master File Directory name:");
  node mfd;
  scanf(" %s",mfd.name);
  mfd.type=FOLDER;
  mfd.child=malloc(20*sizeof(node*));
  int k=0;

  printf("Enter\n1 to add files\n2 to display files\n3 to delete a file\n4 to exit:");
  int i;
repeat:
  scanf("%d",&i);

  switch(i)
  {
    case 1:   if(k<=20)
              {
                mfd.child[k]=malloc(sizeof(node));
                printf("Enter File Name:");
                scanf(" %s",mfd.child[k]->name);
                mfd.child[k]->type=FILE;
                k++;
              }
              break;

    case 2:  ;
             int i;
             for(i=0;i<k;i++)
             printf("%s/%s\n",mfd.name,mfd.child[i]->name);
             break;

    case 3:

  }

  if(i!=3)
  goto repeat;
}
