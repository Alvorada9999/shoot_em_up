#include <SDL2/SDL.h>
#include <SDL2/SDL_scancode.h>
#include <stdint.h>
#include "defs.h"
#include "initSDL.h"

void doKeyDown(SDL_KeyboardEvent *event, App *app) {
  if(event -> repeat == 0) {
    switch (event -> keysym.scancode) {
      case SDL_SCANCODE_UP:
        app -> up = 1;
        break;
      case SDL_SCANCODE_DOWN:
        app -> down = 1;
        break;
      case SDL_SCANCODE_LEFT:
        app -> left = 1;
        break;
      case SDL_SCANCODE_RIGHT:
        app -> right = 1;
        break;
      case SDL_SCANCODE_LCTRL:
        app -> fire = 1;
        break;
    }
  }
}

void doKeyUp(SDL_KeyboardEvent *event, App *app) {
  if(event -> repeat == 0) {
    switch (event -> keysym.scancode) {
      case SDL_SCANCODE_UP:
        app -> up = 0;
        break;
      case SDL_SCANCODE_DOWN:
        app -> down = 0;
        break;
      case SDL_SCANCODE_LEFT:
        app -> left = 0;
        break;
      case SDL_SCANCODE_RIGHT:
        app -> right = 0;
        break;
      case SDL_SCANCODE_LCTRL:
        app -> fire = 0;
        break;
    }
  }
}

void handleInput(uint8_t *isGameRunning, App *app) {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      *isGameRunning = FALSE;
      break;
    case SDL_KEYDOWN:
      doKeyDown(&event.key, app);
      break;
    case SDL_KEYUP:
      doKeyUp(&event.key, app);
      break;
    default:
      break;
  }
}
