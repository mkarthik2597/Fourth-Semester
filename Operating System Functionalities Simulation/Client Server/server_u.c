#include"universal.h"
#include<stdio.h>
#include<string.h>

void error(char* msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char** argv)
{
  int sockfd,portno,n;
  struct sockaddr_in serv_addr,cli_addr;
  socklen_t clilen;
  char buffer[256];
  
  sockfd=socket(AF_INET,SOCK_DGRAM,0);
  portno=atoi(argv[1]);
  clilen=sizeof(cli_addr);
  
  bzero((char*)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_port=htons(portno);
  serv_addr.sin_addr.s_addr=INADDR_ANY;
  
  bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
  
  bzero(buffer,256);
  recvfrom(sockfd,buffer,255,0,(struct sockaddr*)&cli_addr,&clilen);
  puts(buffer);
  
  bzero(buffer,256);
  printf("Enter a message for client");
  scanf(" %s",buffer);
  sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr*)&cli_addr,clilen);
  
  close(sockfd);
}
