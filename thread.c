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

#define DEBUG

void* process_request(void* sockfd_ptr){
  int sockfd = *((int*)sockfd_ptr);

  #ifdef DEBUG
    printf("%i\n", sockfd);
  #endif

  int n = 0;
  char buffer[1024];
  n = read(sockfd,buffer,1024);
  buffer[n] = '\0';
  char* response = "{\"response\":\"ok\"}";
  write(sockfd, response, strlen(response));
  close(sockfd);
  return NULL;
}

int spawn_worker(int sockfd){
  /* process request within thread */
  pthread_t thrd;
  pthread_create(&thrd, NULL, process_request, (void*)&sockfd );
  return 0;
}
