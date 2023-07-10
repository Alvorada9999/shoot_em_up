#ifndef src_initSDL
#define src_initSDL
#include <SDL2/SDL.h>

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
  uint8_t up;
  uint8_t down;
  uint8_t left;
  uint8_t right;
  uint8_t fire;
  Uint64 lastFrameTime;
} App;

App initSDL(void);

#endif
