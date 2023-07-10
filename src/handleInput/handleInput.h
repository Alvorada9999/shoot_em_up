#ifndef src_handleInput
#define src_handleInput

#include <stdint.h>

#include "initSDL.h"

void handleInput(uint8_t *isGameRunning, App *app);
void doKeyDown(SDL_KeyboardEvent *event, App *app);
void doKeyUp(SDL_KeyboardEvent *event, App *app);

#endif
