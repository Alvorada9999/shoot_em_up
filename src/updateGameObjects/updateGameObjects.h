#ifndef src_updateGameObjects
#define src_updateGameObjects

#include <SDL2/SDL.h>
#include <bits/stdint-uintn.h>
#include "initSDL.h"

typedef struct {
  float x;
  float xToAdd;
  float *xRelativeTo;
  float y;
  float yToAdd;
  float *yRelativeTo;
  int w;
  int h;
  int speedInPixels;
  int textureX;
  int textureY;
  int textureW;
  int textureH;
  SDL_Texture *texture;
  int health;
  uint8_t type;
} Entity;

#define PLAYER          0x00000001u
#define BULLET          0x00000010u
void updateGameObjects(Entity *entity, App *app);

#define POSITION         0x00000001u
#define TEXTURE          0x00000010u
SDL_Rect createRectFromEntity(Entity *gameEntity, uint8_t option);

#endif
