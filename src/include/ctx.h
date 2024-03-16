#ifndef CTX_H
#define CTX_H

#include <SDL2/SDL.h>
#include "config.h"
#include "ui.h"

typedef enum {
    INITIALIZING, RUNNING, QUITTING
} State;

typedef struct {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    State state;
    Config *pConfig;
    UI *pUI;
} CTX;

CTX *newCTX();

void loop(CTX *pCTX);

void destroyCTX(CTX *pCTX);

#endif