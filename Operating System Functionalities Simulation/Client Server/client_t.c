#include"universal.h"

void error(char* msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char** argv)
{
  int portno,sockfd,n;
  struct sockaddr_in serv_addr;
  struct hostent* server;
  char buffer[256];
  
  portno=atoi(argv[2]);
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  server=gethostbyname(argv[1]);
  
  bzero((char*)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_port=htons(portno);
  bcopy((char*)server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);
  
  connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
  
  printf("Write a message for the server:");
  bzero(buffer,256);
  scanf(" %s",buffer);
  write(sockfd,buffer,strlen(buffer));
  
  bzero(buffer,256);
  read(sockfd,buffer,255);
  puts(buffer);
  
  close(sockfd);
}
