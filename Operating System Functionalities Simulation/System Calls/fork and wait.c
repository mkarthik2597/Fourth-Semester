#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
  printf("I am the parent process.I will create a child\n");
  pid_t pid=fork();
  printf("This should get printed twice\n");
  
  pid_t return_wait;
  int* status;
  return_wait=wait(status);  
  printf("PID of completed process:%d",return_wait);
  
  if(pid==0)
  { printf("I am the child-%d\n",pid);}
  else
  printf("I am the parent-%d",pid);
  
}
