#pragma once

#include "player.hpp" //the player struct.. needed to make a pointer called NewPlayer.
#include <cstdint> //for "uint32_t *pixels"

void RenderWalls(Player *NewPlayer, uint32_t *pixels); 

//shit is so short s