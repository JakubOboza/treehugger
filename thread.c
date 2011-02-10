#include "thread.h"

void* print_foo(void* ptr){
  char* msg = (char*)ptr;
  printf("%s\n", msg);
  return NULL;
}

int spawn_talker(){
  char* text = "Hi guys! im spawned nigga";
  pthread_t thrd;
  pthread_create( &thrd, NULL, print_foo, (void*) text);
  pthread_join( thrd, NULL);
  return 0;
}
