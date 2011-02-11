#include "thread.h"

void* print_foo(void* ptr){
  char* msg = (char*)ptr;
  printf("%s\n", msg);
  return NULL;
}

int test_spawn(){
  char* text = "Hi guys!";
  pthread_t thrd;
  pthread_create( &thrd, NULL, print_foo, (void*) text);
  pthread_join( thrd, NULL);
  return 0;
}

int spawn_worker(int sockfd){
  /* process request within thread */
  return 0;
}
