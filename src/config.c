#include "include/config.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Config *newConfig() {
    Config *pConfig = (Config *)malloc(sizeof(Config));
    // Maybe read from a config file?
    pConfig->window_name = (char *)malloc(sizeof(strlen("SDL_WINDOW")));
    if(pConfig->window_name == NULL) {
        fprintf(stderr, "Could not allocate memory for the window name!\n");
    }
    strcpy(pConfig->window_name, "SDL_WINDOW");
    pConfig->multithreading = AUTO;
    pConfig->fps = 60;
    pConfig->width = 1920;
    pConfig->height = 1080;

    return pConfig;
}

void destroyConfig(Config *pConfig) {
    if(pConfig != NULL) {
        if(pConfig->window_name != NULL) {
            free(pConfig->window_name);
        }
        free(pConfig);
    }
}