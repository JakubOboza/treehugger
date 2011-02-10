#include <string.h>
#include "configuration.h"
#include "thread.h"

typedef unsigned int bool;
#define true 1
#define false 0

bool test_init_app_config(){
  bool result = true ;
  const app_config* test_conf = init_appconfig();
  /* check defaults */
  if ( test_conf->socket  != 3666) result = false;
  if ( strcmp(test_conf->address,"127.0.0.1") ) result = false;
  return result;
}

bool test_threads(){
  bool result = true;
  if( test_spawn() != 0 ) result = false;
  return result;
}

bool test_fail(){
  return false;
}

bool test_pass(){
  return true;
}

typedef struct {
  char desc[256];
  bool (*test_fun)();
} test_case;

test_case tests[] = {
  { "It should initialize with default values", test_init_app_config},
  { "It should have working threads", test_threads }
};

int main(int argc, char* argv[]){
  int number_of_failures = 0;

  int i = 0;
  for( i = 0 ; i < sizeof(tests)/sizeof(test_case) ; i++){

    if(tests[i].test_fun() == false){
      printf("Failure in: %s \n ", tests[i].desc );
      number_of_failures++;
    }

  }

  return number_of_failures;
}
