#include "player.hpp"

Player PlayerCreate(float SetPosX, float SetPosY, float SetDirX, float SetDirY) {
 //X = NewX; Y = NewY;
 //Yeah.
 Player OurPlayer;
 
 OurPlayer.posX = SetPosX; OurPlayer.posY = SetPosY; 
 OurPlayer.dirX = SetDirX; OurPlayer.dirY = SetDirY;

 OurPlayer.rotatingSpeed = settings::RotateSpeed;
 
 return OurPlayer;
}
