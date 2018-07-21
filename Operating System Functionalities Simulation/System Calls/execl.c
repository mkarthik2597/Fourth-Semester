/* execl(), fork(), wait(), exit(), getuid(), geteuid(), getgid(), getegid(), getpid(), getppid(), signal(), kill(), alarm(), chdir()*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
  //execl("Called_process","Called_process","Hello","World",NULL);
  printf("An error occurred!");
  
  uid_t uid1=getuid();
  uid_t uid2=geteuid();
  
  uid_t uid3=getgid();
  uid_t uid4=getegid();
    
  printf("\n%d %d %d %d\n",uid1,uid2,uid3,uid4);
}

