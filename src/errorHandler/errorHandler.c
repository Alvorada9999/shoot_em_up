#include "errorHandler.h"
#include "SDL2/SDL.h"
#include <unistd.h>

void errorHandler(char *errorMessage, int code, App app) {
  if(app.renderer != NULL) {
    SDL_DestroyRenderer(app.renderer);
  }
  if(app.window != NULL) {
    SDL_DestroyWindow(app.window);
  }
  write(2, errorMessage, strlen(errorMessage)*sizeof(char));
  SDL_Quit();
  exit(code);
}
