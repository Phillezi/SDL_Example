#include "include/render.h"

void render_unhandled(CTX *pCTX) {
    SDL_SetRenderDrawColor(pCTX->pRenderer, 255, 0, 0, 255);
    SDL_RenderClear(pCTX->pRenderer);

    drawText(pCTX->pUI->pText[INFO_TEXT], pCTX->pRenderer);

    SDL_RenderPresent(pCTX->pRenderer);
}

void render_initializing(CTX *pCTX) {
    SDL_SetRenderDrawColor(pCTX->pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pCTX->pRenderer);

    drawText(pCTX->pUI->pText[INIT_TEXT], pCTX->pRenderer);
    drawText(pCTX->pUI->pText[INFO_TEXT], pCTX->pRenderer);

    SDL_RenderPresent(pCTX->pRenderer);
}

void render_running(CTX *pCTX) {
    SDL_SetRenderDrawColor(pCTX->pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pCTX->pRenderer);

    drawText(pCTX->pUI->pText[HELLO_TEXT], pCTX->pRenderer);
    drawText(pCTX->pUI->pText[INFO_TEXT], pCTX->pRenderer);

    SDL_RenderPresent(pCTX->pRenderer);
}

void render_quitting(CTX *pCTX) {
    SDL_SetRenderDrawColor(pCTX->pRenderer, 0, 255, 0, 255);
    SDL_RenderClear(pCTX->pRenderer);

    drawText(pCTX->pUI->pText[QUITTING_TEXT], pCTX->pRenderer);
    drawText(pCTX->pUI->pText[INFO_TEXT], pCTX->pRenderer);

    SDL_RenderPresent(pCTX->pRenderer);
}

void render(CTX *pCTX) {
    switch(pCTX->state) {
        case INITIALIZING: render_initializing(pCTX); break;
        case RUNNING: render_running(pCTX); break;
        case QUITTING: render_quitting(pCTX); break;
        default: render_unhandled(pCTX); break;
    } 
}