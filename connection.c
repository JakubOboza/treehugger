#include "connection.h"

int init_socket(const app_config* config){

  int sockfd = -1;
  struct sockaddr_in serv_addr;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0)printf("Error opening socket\n");

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons( config->port );
  if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) printf("Error binding the socket\n");

  return sockfd;
}

int connection_listen(int sockfd){
  int newsockfd;
  struct sockaddr_in cli_addr;
  socklen_t clilen;

  listen(sockfd, 5);
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if(newsockfd < 0)printf("Error on accepting connection\n");
  return newsockfd;
}



