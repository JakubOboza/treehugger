#ifndef __CONNECTION_TREEHUGGER_H_
#define __CONNECTION_TREEHUGGER_H_

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "configuration.h"
#include "thread.h"

/*
  init our socket and return it, in case of error print to STDERR and return -1
*/
int init_socket(const app_config* config);
int connection_listen(int sockfd);



#endif
