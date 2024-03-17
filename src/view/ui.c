#include "include/ui.h"
#include <stdlib.h>
#include <stdio.h>

UI *newUI(const char *fontPath, int fontSize) {
    UI *pUI = (UI *)malloc(sizeof(UI));
    for(int i = 0; i < OUT_OF_BOUNDS_TEXT; i++) {
        pUI->pText[i] = NULL;
    }
    if(pUI == NULL) {
        fprintf(stderr, "Could not allocate memory for UI!\n");
        return NULL;
    }
    pUI->pFont = TTF_OpenFont(fontPath, fontSize);
    if(pUI->pFont == NULL) {
        destroyUI(pUI);
        fprintf(stderr, "Could not create font! %s\n", TTF_GetError());
        return NULL;
    }
    
    return pUI;
}

void destroyUI(UI *pUI) {
    if(pUI != NULL) {
        if(pUI->pFont != NULL) {
            TTF_CloseFont(pUI->pFont);
        }
        for(int i = 0; i < OUT_OF_BOUNDS_TEXT; i++) {
            if(pUI->pText[i] != NULL) {
                destroyText(pUI->pText[i]);
            }
        }
        free(pUI);
    }
}