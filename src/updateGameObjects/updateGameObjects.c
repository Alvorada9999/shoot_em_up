#include "updateGameObjects.h"
#include <SDL2/SDL_timer.h>
#include <string.h>
#include "initSDL.h"
#include "defs.h"

void updateGameObjects(Entity *entity, App *app) {
  float deltaTime = (SDL_GetTicks64() - app -> lastFrameTime) / 1000.0f;
  switch ((*entity).type) {
    case PLAYER:
      if(app -> up) {
        entity -> y -= entity -> speedInPixels*deltaTime;
      }
      if(app -> down) {
        entity -> y += entity -> speedInPixels*deltaTime;
      }
      if(app -> left) {
        entity -> x -= entity -> speedInPixels*deltaTime;
      }
      if(app -> right) {
        entity -> x += entity -> speedInPixels*deltaTime;
      }
      break;
    case BULLET:
      if(entity -> x > WINDOW_WIDTH) {
        entity -> health = 0;
      }
      if(entity -> health > 0) {
        entity -> x += entity -> speedInPixels*deltaTime;
      } else {
        if(app -> fire) {
          entity -> x = *(entity -> xRelativeTo) + entity -> xToAdd;
          entity -> y = *(entity -> yRelativeTo) + entity -> yToAdd;
          entity -> health = 1;
        }
      }
      break;
  }
}

SDL_Rect createRectFromEntity(Entity *gameEntity, uint8_t option) {
  SDL_Rect rect;
  memset(&rect, 0, sizeof(rect));
  if(option == POSITION) {
    rect.x = gameEntity -> x;
    rect.y = gameEntity -> y;
    rect.w = gameEntity -> w;
    rect.h = gameEntity -> h;
    return rect;
  }
  if(option == TEXTURE) {
    rect.x = gameEntity -> textureX;
    rect.y = gameEntity -> textureY;
    rect.w = gameEntity -> textureW;
    rect.h = gameEntity -> textureH;
    return rect;
  }
  return rect;
}
