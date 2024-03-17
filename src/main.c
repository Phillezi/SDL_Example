#include "controller/include/ctx.h"

int main(int argc, char **argv) {
    CTX *pCTX = newCTX();
    
    loop(pCTX);

    destroyCTX(pCTX);
    return 0;
}