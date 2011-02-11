#ifndef __TREEHUGGER_THREAD_H_
#define __TREEHUGGER_THREAD_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int test_spawn();

int spawn_worker(int sockfd);

#endif
