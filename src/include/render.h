#ifndef RENDER_H
#define RENDER_H

#include "ctx.h"

void render_unhandled(CTX *pCTX);

void render_initializing(CTX *pCTX);

void render_running(CTX *pCTX);

void render_quitting(CTX *pCTX);

void render(CTX *pCTX);

#endif