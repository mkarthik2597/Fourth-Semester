#include"universal.h"

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
  struct hostent* server;
  
  sockfd=socket(AF_INET,SOCK_DGRAM,0);
  portno=atoi(argv[2]);
  server=gethostbyname(argv[1]);
  clilen=sizeof(cli_addr);
  
  bzero((char*)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_port=htons(portno);
  bcopy((char*)server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);
  
  printf("Enter a message for the server:");
  bzero(buffer,256);
  scanf(" %s",buffer);
  sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr*)&serv_addr,clilen);
  
  bzero(buffer,256);
  recvfrom(sockfd,buffer,255,0,(struct sockaddr*)&cli_addr,&clilen);
  puts(buffer);
  
  close(sockfd);
}
