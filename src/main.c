#include <stdint.h>
#include <stdio.h>

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "initSDL.h"
#include "handleInput.h"
#include "updateGameObjects.h"
#include "render.h"
#include "errorHandler.h"
#include "updateGameObjects.h"

uint8_t isGameRunning = TRUE;

int main(int argc, char* argv[], char** envp) {
  App app;
  Entity player, bullet1, bullet2;
  memset(&app, 0, sizeof(app));
  memset(&player, 0, sizeof(player));
  app = initSDL();
  SDL_Texture *globalTexture = loadTexture(app.renderer, "assets/16ShipCollection.png");

  player.x = 450;
  player.y = 45;
  player.w = 50;
  player.h = 50;
  player.speedInPixels = 350;
  player.textureX = 288;
  player.textureY = 322;
  player.textureW = 16;
  player.textureH = 16;
  player.texture = globalTexture;
  player.health = 1;
  player.type = PLAYER;

  bullet1.x = player.x + 45;
  bullet1.xToAdd = 45;
  bullet1.xRelativeTo = &(player.x);
  bullet1.y = player.y + 20;
  bullet1.yToAdd = 20;
  bullet1.yRelativeTo = &(player.y);
  bullet1.w = 4;
  bullet1.h = 2;
  bullet1.speedInPixels = 1920;
  bullet1.textureX = 301;
  bullet1.textureY = 559;
  bullet1.textureW = 1;
  bullet1.textureH = 1;
  bullet1.texture = globalTexture;
  bullet1.health = 0;
  bullet1.type = BULLET;

  bullet2.x = player.x + 45;
  bullet2.xToAdd = 45;
  bullet2.xRelativeTo = &(player.x);
  bullet2.y = player.y + 28;
  bullet2.yToAdd = 28;
  bullet2.yRelativeTo = &(player.y);
  bullet2.w = 4;
  bullet2.h = 2;
  bullet2.speedInPixels = 1920;
  bullet2.textureX = 301;
  bullet2.textureY = 559;
  bullet2.textureW = 1;
  bullet2.textureH = 1;
  bullet2.texture = globalTexture;
  bullet2.health = 0;
  bullet2.type = BULLET;

  Entity *entityArray[3];
  entityArray[0] = &player;
  entityArray[1] = &bullet1;
  entityArray[2] = &bullet2;

  while(isGameRunning) {
    prepareScene(app.renderer);
    handleInput(&isGameRunning, &app);
    for(int i=0; i<3; i++) {
      updateGameObjects(entityArray[i], &app);
      if(entityArray[i] -> health > 0) {
        blit(app.renderer, createRectFromEntity(entityArray[i], POSITION), entityArray[i] -> texture, createRectFromEntity(entityArray[i], TEXTURE));
      }
    }
    presentScene(&app);
    SDL_Delay(FRAME_TARGET_TIME);
  }

  if(app.renderer != NULL) {
    SDL_DestroyRenderer(app.renderer);
  }
  if(app.window != NULL) {
    SDL_DestroyWindow(app.window);
  }
  SDL_Quit();
  return 0;
}
