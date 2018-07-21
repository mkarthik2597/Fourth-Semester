#include"universal.h"

void error(char* msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char** argv)
{
  int portno,n,sockfd,newsockfd;
  char buffer[256];
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  
  portno=atoi(argv[1]);
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  if(sockfd<0)
  error("Failed to create socket");
  clilen=sizeof(cli_addr);
  
  bzero((char*)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_port=htons(portno);
  serv_addr.sin_addr.s_addr=INADDR_ANY;
  
  if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0)
  error("Failed to bind");
  
  listen(sockfd,5);
  newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
  if(newsockfd<0)
  error("Failed to accept connection from client");
  
  int i;
  
  bzero(buffer,256);
  read(newsockfd,buffer,256);
  puts(buffer);
  
  printf("Type in a message:");
  
  bzero(buffer,256);
  scanf(" %s",buffer);
  write(newsockfd,buffer,strlen(buffer));
  
  close(sockfd);
  close(newsockfd);
}
