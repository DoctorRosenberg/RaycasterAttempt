#include "RaycasterRenderer.hpp" //The original header file. It said that the function exists, and this cpp explains everything.
#include "player.hpp" //The header for player struct. YOU, after all.
#include <cmath> //For math shit i dont really know math
#include <cstdint> //ehh for that pixels variable 
#include <memory> //for the smart pointer as a map to laod
#include "LoadUserSettings.hpp" //the header for namespace settings

//This isn't used now.
//void RenderWalls(size_t mapX, size_t mapY, float map[mapX][mapY], Player *NewPlayer, uint32_t *pixels) {



void RenderWalls(Player *NewPlayer, uint32_t *pixels) {

 auto map2D = [&](size_t x, size_t y) {
    return settings::LoadedMap[y * settings::LoadedMapWidth + x];
 };

 for (int c = 0; c < settings::ScreenWidth; c++) {

  float cameraX = 2*c/float(settings::ScreenWidth) - 1;
  float rayDirX = NewPlayer->dirX+NewPlayer->planeX()*cameraX;
  float rayDirY = NewPlayer->dirY+NewPlayer->planeY()*cameraX;
  
  //This is in which box we are.
  int gridX = int(NewPlayer->posX);
  int gridY = int(NewPlayer->posY);
  
  //length of ray from you to the next wall.
  float sideDistX;
  float sideDistY;
  
  //delta
  float deltaDistX = (rayDirX == 0) ? 1e30f : std::abs(1.0f / rayDirX);
  float deltaDistY = (rayDirY == 0) ? 1e30f : std::abs(1.0f / rayDirY);
  
  //Perpendicular wall distance.
  float PerpendicularDist;
  
  //direction to step in.
  int stepX;
  int stepY;
  
  int hit = 0; //cool variable with 0
  int side; //what was the hit variable
  
  //Calculate.
  
  if (rayDirX < 0) {
   stepX = -1;
   sideDistX = (NewPlayer->posX - gridX) * deltaDistX;
  }
  else {
   stepX = 1;
   sideDistX = (gridX + 1.0f - NewPlayer->posX) * deltaDistX;
  }
  if (rayDirY < 0) {
   stepY = -1;
   sideDistY = (NewPlayer->posY - gridY) * deltaDistY;
  }
  else {
   stepY = 1;
   sideDistY = (gridY + 1.0f - NewPlayer->posY) * deltaDistY;
  }
  //DDA!!!
  while (hit == 0) {
   if (sideDistX < sideDistY) {
    sideDistX += deltaDistX;
    gridX += stepX;
    side = 0;
   }
   else {
    sideDistY += deltaDistY;
    gridY += stepY;
    side = 1;
   }
   
  
  if (gridX < 0 || gridX >= (int)settings::LoadedMapWidth || gridY < 0 || gridY >= (int)settings::LoadedMapHeight) break;
  
  if (map2D(gridX, gridY) > 0.0f) hit = 1;
  
  }
  
  //uhhh
  if (side == 0) PerpendicularDist = (sideDistX - deltaDistX);
  else PerpendicularDist = (sideDistY - deltaDistY);
  
  if (PerpendicularDist < 0.0001f) PerpendicularDist = 0;
  
  //Height of the line.
  int lineHeight = (int) (settings::ScreenHeight / PerpendicularDist);
  
  //Calculate pixels.
  int drawStart =- lineHeight / 2 + settings::ScreenHeight / 2;
  if (drawStart < 0) drawStart = 0;
  int drawEnd = lineHeight / 2 + settings::ScreenHeight / 2;
  if (drawEnd >= settings::ScreenHeight) drawEnd = settings::ScreenHeight -1;
  
  uint32_t color = (side == 1) ? 0x990000FF : 0xDD0000FF;
  
  for (int y = drawStart; y < drawEnd; y++) {
   pixels[y*settings::ScreenWidth+c] = color;

  }
  
  }
 
}
