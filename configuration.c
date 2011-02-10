#include "configuration.h"

app_config* init_appconfig(){
  app_config* config = malloc(sizeof(app_config));
  config->socket = DEFAULT_SOCK;
  config->address = malloc(sizeof(char) * 10);
  config->address = "127.0.0.1";
  return config;
}

const app_config* appconfig(){
  app_config* config = init_appconfig();
  /* TODO:
     Read the config from json and fill into struct
  */
  return config;
}
