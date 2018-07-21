#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FOLDER 1
#define FILE 0

struct node
{
  char name[20];
  int type;
  struct node** child;
  int nchild;
};
typedef struct node node;

void display(node);
void userspace(node*,node);

int main()
{
  printf("Note:The MFD can support atmost 5 users and each user can have 20 files\n");
  printf("Enter the name of MFD:");
  node mfd;
  mfd.type=FOLDER;
  scanf(" %s",mfd.name);
  mfd.child=malloc(5*sizeof(node*));
  mfd.nchild=0;

  char buf[20];
  printf("Enter\n1 to add a user\n2 to remove a user\n3 to go to a user directory\n4 to display directory");
  printf("structure\n5 to exit:");
  int i;
repeat:
  printf("\n>>");
  scanf("%d",&i);
  switch(i)
  {
    case 1:  if(mfd.nchild<=5)
             {
               mfd.child[mfd.nchild]=malloc(sizeof(node));
               printf("Enter new user name:");
               scanf(" %s",mfd.child[mfd.nchild]->name);
               mfd.child[mfd.nchild]->type=FOLDER;
               mfd.child[mfd.nchild]->child=malloc(20*sizeof(node*));
               mfd.child[mfd.nchild]->nchild=0;
               mfd.nchild++;

               display(mfd);
             }
             break;

    case 2: if(mfd.nchild>0)
            {
              printf("Enter user name:");
              scanf(" %s",buf);

              int i;
              for(i=0;i<mfd.nchild;i++)
              if(strcmp(mfd.child[i]->name,buf)==0)
              {
                free(mfd.child[i]);
                int j;
                for(j=i;j<mfd.nchild-1;j++)
                mfd.child[j]=mfd.child[j+1];

                mfd.nchild--;

                break;
              }

              display(mfd);
            }

    case 3: printf("Enter user name:");
            scanf(" %s",buf);

            for(i=0;i<mfd.nchild;i++)
            if(strcmp(mfd.child[i]->name,buf)==0)
            {
              userspace(mfd.child[i],mfd);
              break;
            }
            break;

    case 4: display(mfd);
            break;

  }

  if(i!=5)
  goto repeat;
}

void display(node mfd)
{
  int i,j;

  printf("%s\n\n",mfd.name);
  for(i=0;i<mfd.nchild;i++)
  {
    printf("%s\n",mfd.child[i]->name);

    for(j=0;j<mfd.child[i]->nchild;j++)
    {
      printf("%s\n",mfd.child[i]->child[j]->name);
    }
    printf("\n");

  }
}

void userspace(node* node_ptr, node mfd)
{
  node user= *node_ptr;
  char buf[20];
  printf("Enter\n1 to add files\n2 to display files\n3 to delete files\n4 to exit:");
  int i;
repeat:
  printf("\n>>");
  scanf("%d",&i);

  switch(i)
  {
    case 1:   if(user.nchild<=20)
              {
                user.child[user.nchild]=malloc(sizeof(node));
                printf("Enter File Name:");
                scanf(" %s",user.child[user.nchild]->name);
                user.child[user.nchild]->type=FILE;
                user.nchild++;
              }
              break;

    case 2:  ;
             for(i=0;i<user.nchild;i++)
             printf("%s\n",user.child[i]->name);
             break;

    case 3: ;
            int i;
            printf("Enter file name:");
            scanf(" %s",buf);
            for(i=0;i<user.nchild;i++)
            {
              if(strcmp(user.child[i]->name,buf)==0)
              {
                free(user.child[i]);
                int j=i;

                for(j=i;j<user.nchild-1;j++)
                user.child[j]=user.child[j+1];

                user.nchild--;
                break;
              }
            }

  }

  if(i!=4)
  goto repeat;

  *node_ptr=user;
}
