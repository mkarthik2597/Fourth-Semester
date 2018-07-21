#include<stdio.h>
#include<stdlib.h>

#define FOLDER 0
#define FILE 1

struct node
{
  char name[20];
  int type;
  struct node** child;
  int nchild;
};
typedef struct node node;

void userspace(node*,node);

int main()
{
  printf("Note:The MFD can support atmost 5 users\n");
  printf("Enter the name of MFD:");
  node mfd;
  mfd.type=FOLDER;
  scanf(" %s",mfd.name);
  mfd.child=malloc(5*sizeof(node*));
  mfd.nchild=0;

  char buf[20];
  printf("Enter\n1 to add a user\n2 to remove a user\n3 to go to a user directory\n4 to exit:");
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
                if(mfd.child[i]->nchild>0)
                {
                  printf("This user directory is not empty.Cannot delete them!");
                  break;
                }
                free(mfd.child[i]);
                int j;
                for(j=i;j<mfd.nchild-1;j++)
                mfd.child[j]=mfd.child[j+1];

                mfd.nchild--;

                break;
              }

            }

    case 3: ;
            node* head=&mfd;
            printf("Enter sub-dir no, else -1 to stop:");
            int x;
            while(1)
            {
              printf("Enter SubDir of %s",head->name);
              scanf("%d",&x);

              if(x!=-1)
              {
                if(head->child[x]->type==FOLDER)
                head=head->child[x];
                else
                printf("\n%s is a file!",head->child[x]->name);
              }
              else
              {
                userspace(head,mfd);
                break;
              }

          }

  }

  if(i!=4)
  goto repeat;
}

void userspace(node* node_ptr, node mfd)
{
  node user= *node_ptr;
  char buf[20];
  printf("Enter\n1 to add files/folders\n2 to display current dir\n3 to delete files/folders:");
  int i;
repeat:
  printf("\n>>");
  scanf("%d",&i);

  switch(i)
  {
    case 1:   if(user.nchild<=20)
              {
                user.child[user.nchild]=malloc(sizeof(node));
                printf("Enter File/Folder Name:");
                scanf(" %s",user.child[user.nchild]->name);
                printf("Enter 0 for folder and 1 for file:");
                int type;
                scanf("%d",&type);
                user.child[user.nchild]->type=type;
                user.nchild++;
              }
              break;

    case 2:  ;
             for(i=0;i<user.nchild;i++)
             printf("%s %d\n",user.child[i]->name, user.child[i]->type);
             break;

    case 3: ;
            int i;
            printf("Enter file/folder name:");
            scanf(" %s",buf);
            for(i=0;i<user.nchild;i++)
            {
              if(strcmp(user.child[i]->name,buf)==0)
              {
                if(user.child[i]->type==FOLDER && user.child[i]->nchild>0)
                {
                  printf("This folder is not empty. Cannot delete the folder!");
                  break;
                }
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
