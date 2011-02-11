#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "connection.h"
#include "thread.h"

#define DEBUG

int main(int argc, char* argv[]){

  /* initialize configuration */
  int server_sockfd = init_socket(init_appconfig());
  /* initialize hash table and pointer table */

  /* initialize append only file */


  while(1){
  /* start listening on port */
    int client_sock = connection_listen(server_sockfd);

  /* accept and spawn working thread to serve data for client */
    spawn_worker(client_sock);
  /* repeat */
  }

  close(server_sockfd);
  return 0;

}

