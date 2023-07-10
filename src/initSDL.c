#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

#include "errorHandler.h"
#include "initSDL.h"
#include "render.h"
#include "errorHandler.h"
#include "defs.h"

App initSDL(void) {
  App app;
  memset(&app, 0, sizeof(app));

  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    errorHandler("Error when initializing sdl", 1, app);
  };

  app.window = SDL_CreateWindow("shoot them", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_VULKAN);
  if(app.window == NULL) {
    errorHandler("Error when creating window", 2, app);
  }

  app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(app.renderer == NULL) {
    errorHandler("Error when creating renderer", 3, app);
  }

  if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0) {
    errorHandler("Error when initializing sdl image", 4, app);
  }
  app.lastFrameTime = 0;

  return app;
}
