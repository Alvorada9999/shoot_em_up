#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>

#include "initSDL.h"

void prepareScene(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 1, 1, 1, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
}

void presentScene(App *app) {
  SDL_RenderPresent(app -> renderer);
  app -> lastFrameTime = SDL_GetTicks64();
}

SDL_Texture *loadTexture(SDL_Renderer *renderer, char *filePath) {
  SDL_Texture *texture;
  SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filePath);
  texture = IMG_LoadTexture(renderer, filePath);
  return texture;
}

void blit(SDL_Renderer *renderer, SDL_Rect rendererRect, SDL_Texture *texture, SDL_Rect textureRect) {
  SDL_RenderCopy(renderer, texture, &textureRect, &rendererRect);
}
