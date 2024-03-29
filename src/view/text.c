#include "include/text.h"
#include <stdlib.h>
#include <stdio.h>

Text *newText(SDL_Renderer *pRenderer, int r, int g, int b, TTF_Font *pFont, char *pString, int x, int y) {
    Text *pText = malloc(sizeof(Text));
    if(pText == NULL) {
        fprintf(stderr, "Could not allocate memory for the text!\n");
        return NULL;
    }
    SDL_Color color = {r,g,b};
    SDL_Surface *pSurface = TTF_RenderText_Solid(pFont, pString, color);
    if(pSurface == NULL) {
        destroyText(pText);
        fprintf(stderr, "Could not create surface! %s\n", SDL_GetError());
        return NULL;
    }
    pText->pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
    SDL_FreeSurface(pSurface);
    if(pText->pTexture == NULL) {
        destroyText(pText);
        fprintf(stderr, "Could not create texture! %s\n", SDL_GetError());
        return NULL;
    }
    SDL_QueryTexture(pText->pTexture, NULL, NULL, &pText->rect.w, &pText->rect.h);
    pText->rect.x = x - pText->rect.w/2;
    pText->rect.y = y - pText->rect.h/2;

    return pText;
}

void drawText(Text *pText, SDL_Renderer *pRenderer) {
    if(pText != NULL) {
        SDL_RenderCopy(pRenderer, pText->pTexture, NULL, &pText->rect);
    }
}

void destroyText(Text *pText) {
    if(pText != NULL) {
        if(pText->pTexture != NULL) {
            SDL_DestroyTexture(pText->pTexture);
        }
        free(pText);
    }
}