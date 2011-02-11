#ifndef __CONFIG_TREEHUGGER_H_
#define __CONFIG_TREEHUGGER_H_

#include <stdlib.h>

#define DEFAULT_PORT 3666

typedef struct {
  int port;
  char* address;
} app_config;

const app_config* appconfig();
app_config* init_appconfig();

#endif
