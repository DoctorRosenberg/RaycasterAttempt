#include "player.hpp"
#include "LoadUserSettings.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

void LoadSettingsMain() {
    std::ios_base::sync_with_stdio(false);
    
    std::ifstream LoadedSettings("settings.txt"); //gets your settings
    
    //the thing below is what happens if you deleted the settings file.
    if (!(LoadedSettings.is_open())) {
        std::ofstream DefaultSettings("settings.txt");

        //this is what happens if you're unable to make a new file again. I wrote this because i could and was thinking of what to do.
        if (!(DefaultSettings.is_open())) {
            std::cerr << "Error.. Couldn't get the settings file and create a new one.";
        }


        DefaultSettings << "ScreenWidth = 1280\nScreenHeight = 720\nMap = ./maps/default_map.txt\nRotateSpeed = 2.5\nFullscreen = false\n";

        DefaultSettings.close();
        
        LoadedSettings.open("settings.txt");

    }
    
    std::string Key;
    std::string EqualsSign;

    while (LoadedSettings >> Key >> EqualsSign) {
        if (Key == "ScreenWidth") {
             LoadedSettings >> settings::ScreenWidth;
        }

        if (Key == "ScreenHeight") {
            LoadedSettings >> settings::ScreenHeight;
        }

        if (Key == "Map") {
            LoadedSettings >> settings::MapPath;
            LoadSettingsMap();
        }

        if (Key == "RotateSpeed") {
            LoadedSettings >> settings::RotateSpeed;
        }
        if (Key == "Fullscreen") {
            LoadedSettings >> settings::FullScreen;
        }
    }
    
}

void LoadSettingsMap() {
    std::ifstream MapFile(settings::MapPath);
    
    if (!(MapFile.is_open())) {
        std::cerr << "Error. Invalid map path.";
    }

    MapFile >> settings::LoadedMapWidth >> settings::LoadedMapHeight;
    
    //std::cout << "\n--- a quick check of success in this map ---" << std::endl;
    //std::cout << "X: " << settings::LoadedMapWidth << "Y" << settings::LoadedMapHeight << std::endl;

    settings::LoadedMap = std::make_unique<float[]>(settings::LoadedMapWidth * settings::LoadedMapHeight);

    for (size_t y = 0; y < settings::LoadedMapHeight; ++y) {
        for (size_t x = 0; x < settings::LoadedMapWidth; ++x) {
            MapFile >> settings::LoadedMap[y * settings::LoadedMapWidth + x];
        } 
        std::cout << std::endl;
    }

    MapFile >> settings::PlayerSpawnX >> settings::PlayerSpawnY;

    MapFile >> settings::PlayerSpawnLookX >> settings::PlayerSpawnLookY;
    
    //std::cout << "Player created in: X=" << settings::PlayerSpawnX << ", Y=" << settings::PlayerSpawnY << std::endl;
    //std::cout << "-------------------------------------------\n" << std::endl;

}






















//What is it below?

//void LoadSettingsClient(int NewScreenWidth, int NewScreenHeight, int NewRotateSpeed) {
// settings::ScreenWidth = NewScreenWidth; settings::ScreenHeight = NewScreenHeight;
// settings::RotateSpeed = NewRotateSpeed;
//}

//That's a function i made before making the main. I thought i'd need this, but, no.
