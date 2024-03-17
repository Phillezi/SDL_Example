#ifndef UI_H
#define UI_H

#include <SDL2/SDL_ttf.h>
#include "text.h"

typedef enum {
    INIT_TEXT, HELLO_TEXT, QUITTING_TEXT, INFO_TEXT, OUT_OF_BOUNDS_TEXT
} TextIndex;

typedef struct {
    TTF_Font *pFont;
    Text *pText[OUT_OF_BOUNDS_TEXT];
} UI;

UI *newUI(const char *fontPath, int fontSize);

void destroyUI(UI *pUI);

#endif