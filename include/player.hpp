#pragma once

#include <cmath>
#include "LoadUserSettings.hpp"

struct Player {
 float posX, posY; //Where is our player? Hm.. There he is! In (5, 10)! This basically means where you are on the 2d map.
 float dirX, dirY; //Where are you looking.
 
 const float fov = 1.57079f; //90 FOV.
 
 float planeX() const { return -dirY * tan(fov / 2.0f); } //IDK myself
 float planeY() const { return dirX * tan(fov / 2.0f); } //about this too
 
 const float speed = 2.0f;
 float rotatingSpeed;
 
 const float PlayerRadius = 0.2f;
};

Player PlayerCreate(float SetPosX, float SetPosY, float SetDirX, float SetDirY); //Don't be afraid, that's struct creation.