#pragma once

#include <memory>
#include <string>

//This is settings namespace. Variables, defined by user or by default in settings.txt.
namespace settings {
 //user's screen
 inline int ScreenWidth;
 inline int ScreenHeight;
 inline bool FullScreen;
 //user's mouse rotating speed
 inline float RotateSpeed;
 //user's map path
 inline std::string MapPath;
 //user's map properties
 inline size_t LoadedMapWidth;
 inline size_t LoadedMapHeight;
 //where's player will be in the map
 inline float PlayerSpawnX;
 inline float PlayerSpawnY;
 
 //inline float LoadedMap[LoadedMapWidth][LoadedMapHeight];
 //i've used a STACK variable before.

 inline std::unique_ptr<float[]> LoadedMap = nullptr;
}
//This function is made to load the most of the variables 
void LoadSettingsMain();

//This function is made to load a map from the set path.
void LoadSettingsMap();

//void LoadSettingsClient(int NewScreenWidth, int NewScreenHeight, float NewRotateSpeed);



