#ifndef TEXT_H
#define TEXT_H
#include <SDL2/SDL_ttf.h>

typedef struct {
    SDL_Rect rect;
    SDL_Texture *pTexture;
} Text;

Text *newText(SDL_Renderer *pRenderer, int r, int g, int b, TTF_Font *pFont, char *pString, int x, int y);

void drawText(Text *pText, SDL_Renderer *pRenderer);

void destroyText(Text *pText);


#endif