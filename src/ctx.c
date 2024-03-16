#include "include/ctx.h"
#include <stdlib.h>
#include "include/render.h"
#include <stdio.h>

/**
 * @brief Create a new CTX.
 * 
 * @return CTX* A pointer to a new CTX (on the heap).
 */
CTX *newCTX() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not init SDL! %s\n", SDL_GetError());
        return NULL;
    }

    if(TTF_Init() < 0) {
        fprintf(stderr, "Could not init TTF! %s\n", TTF_GetError());
        return NULL;
    }

    CTX *pCTX = (CTX *)malloc(sizeof(CTX));
    pCTX->pConfig = newConfig();
    if(pCTX->pConfig == NULL) {
        destroyCTX(pCTX);
        fprintf(stderr, "Could not create config!\n");
        return NULL;
    }
    pCTX->pWindow = SDL_CreateWindow(pCTX->pConfig->window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pCTX->pConfig->width, pCTX->pConfig->height, 0);
    if(pCTX->pWindow == NULL) {
        destroyCTX(pCTX);
        fprintf(stderr, "Could not create window! %s\n", SDL_GetError());
        return NULL;
    }
    pCTX->pRenderer = SDL_CreateRenderer(pCTX->pWindow, -1, SDL_RENDERER_ACCELERATED);
    if(pCTX->pWindow == NULL) {
        destroyCTX(pCTX);
        fprintf(stderr, "Could not create window! %s\n", SDL_GetError());
        return NULL;
    }
    pCTX->pUI = newUI("./res/RetroGaming.ttf", pCTX->pConfig->height/5);
    if(pCTX->pUI == NULL) {
        destroyCTX(pCTX);
        fprintf(stderr, "Could not create ui!\n");
        return NULL;
    }
    pCTX->pUI->pText[INIT_TEXT] = newText(pCTX->pRenderer, 200, 200, 200, pCTX->pUI->pFont, "Initializing", pCTX->pConfig->width/2, pCTX->pConfig->height/2);
    pCTX->pUI->pText[HELLO_TEXT] = newText(pCTX->pRenderer, 200, 200, 200, pCTX->pUI->pFont, "Hello World!", pCTX->pConfig->width/2, pCTX->pConfig->height/2);
    pCTX->pUI->pText[INFO_TEXT] = newText(pCTX->pRenderer, 200, 200, 255, pCTX->pUI->pFont, "Press r or q", pCTX->pConfig->width/2, (3*pCTX->pConfig->height)/4);
    pCTX->pUI->pText[QUITTING_TEXT] = newText(pCTX->pRenderer, 200, 200, 200, pCTX->pUI->pFont, "Quitting...", pCTX->pConfig->width/2, pCTX->pConfig->height/2);

    pCTX->state = INITIALIZING;

    

    return pCTX;
}

/**
 * @brief Runs the program.
 * 
 * @param pCTX The context of the program.
 */
void loop(CTX *pCTX) {
    while(SDL_TRUE) {
        render(pCTX);
        SDL_Event event;
        if(SDL_WaitEventTimeout(&event, 1000/pCTX->pConfig->fps)) { // this updates whenever it needs to or when the timer runs out (keeping the desired fps). For efficiency set th timeout to something like 500ms
            if(event.type == SDL_QUIT) {
                pCTX->state = QUITTING;
                return;
            }
            else if(event.type == SDL_KEYDOWN) {
                switch(event.key.keysym.sym) {
                    case SDLK_r: pCTX->state = RUNNING; break;
                    case SDLK_q: pCTX->state = INITIALIZING; break;
                    default: break;
                }
            }
        }
    }
}

/**
 * @brief Frees the resources of the CTX.
 * 
 * @param pCTX The CTX to free.
 */
void destroyCTX(CTX *pCTX) {
    if(pCTX != NULL) {
        if(pCTX->pRenderer != NULL) {
            SDL_DestroyRenderer(pCTX->pRenderer);
        }
        if(pCTX->pWindow != NULL) {
            SDL_DestroyWindow(pCTX->pWindow);
        }
        if(pCTX->pConfig != NULL) {
            destroyConfig(pCTX->pConfig);
        }
        if(pCTX->pUI != NULL) {
            destroyUI(pCTX->pUI);
        }
        free(pCTX);
    }
    TTF_Quit();
    SDL_Quit();
}