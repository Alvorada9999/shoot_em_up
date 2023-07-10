#ifndef src_render
#define src_render
#include "initSDL.h"
#include <SDL2/SDL_rect.h>

void prepareScene(SDL_Renderer *renderer);
void presentScene(App *app);
SDL_Texture *loadTexture(SDL_Renderer *renderer, char *filePath);
void blit(SDL_Renderer *renderer, SDL_Rect rendererRect, SDL_Texture *texture, SDL_Rect textureRect);

#endif
