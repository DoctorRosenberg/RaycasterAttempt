#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include "LoadUserSettings.hpp"
#include "player.hpp"
#include "RaycasterRenderer.hpp"
#include <iostream>
#include <vector>
#include <cstdint>

int main(int argc, char* argv[]) {
   LoadSettingsMain();
    
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL3 Raycaster", settings::ScreenWidth, settings::ScreenHeight, 0);
    if (!window) {
        std::cerr << "Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cerr << "Renderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Allocate an streaming texture in RGBA8888 format
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, settings::ScreenWidth, settings::ScreenHeight);
    std::vector<uint32_t> pixelBuffer(settings::ScreenWidth * settings::ScreenHeight);

    bool running = true;
    
    SDL_SetWindowFullscreen(window, settings::FullScreen);
    SDL_SetWindowRelativeMouseMode(window, true);


    auto map2D = [&](size_t x, size_t y) {
        return settings::LoadedMap[y * settings::LoadedMapWidth + x]; 
    };

    Uint32 lastTime = SDL_GetTicks();
    
    //He's going to fight with us, just wait!
    Player OurPlayer = PlayerCreate(settings::PlayerSpawnX, settings::PlayerSpawnY, settings::PlayerSpawnLookX, settings::PlayerSpawnLookY); //OUR HERO! He's HERE!!
    
    RenderWalls(&OurPlayer, pixelBuffer.data());
    
    while (running) {

        Uint32 now = SDL_GetTicks();
        float deltaTime = (now - lastTime) / 1000.0f;
        lastTime = now;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.type == SDL_EVENT_MOUSE_MOTION) {
                float mouse_dx = event.motion.xrel; 
                float rotSpeed = mouse_dx * OurPlayer.rotatingSpeed * deltaTime;
                float oldDirX = OurPlayer.dirX;


                OurPlayer.dirX = OurPlayer.dirX * std::cos(rotSpeed) - OurPlayer.dirY * std::sin(rotSpeed);
                OurPlayer.dirY = oldDirX * std::sin(rotSpeed) + OurPlayer.dirY * std::cos(rotSpeed);
            }
        }

        //they were here before.

        //Uint32 now = SDL_GetTicks();
        //float deltaTime = (now - lastTime) / 1000.0f;
        //lastTime = now;


        // Keyboard inputs using updated SDL3 states
        const bool* keys = SDL_GetKeyboardState(NULL);
        if (keys[SDL_SCANCODE_ESCAPE]) running = false;

        float moveX = 0.0f;
        float moveY = 0.0f;

        if (keys[SDL_SCANCODE_W]) {
            moveX += OurPlayer.dirX;
            moveY += OurPlayer.dirY;
        }
        
        if (keys[SDL_SCANCODE_RIGHT]) {
            float rotSpeed = OurPlayer.rotatingSpeed * deltaTime;
            float oldDirX = OurPlayer.dirX;
            OurPlayer.dirX = OurPlayer.dirX * std::cos(rotSpeed) - OurPlayer.dirY * std::sin(rotSpeed);
            OurPlayer.dirY = oldDirX * std::sin(rotSpeed) + OurPlayer.dirY * std::cos(rotSpeed);
        }

        if (keys[SDL_SCANCODE_S]) {
            moveX -= OurPlayer.dirX;
            moveY -= OurPlayer.dirY;
        }

        if (keys[SDL_SCANCODE_LEFT]) {
            float rotSpeed = OurPlayer.rotatingSpeed * deltaTime;
            float oldDirX = OurPlayer.dirX;
            OurPlayer.dirX = OurPlayer.dirX * std::cos(-rotSpeed) - OurPlayer.dirY * std::sin(-rotSpeed);
            OurPlayer.dirY = oldDirX * std::sin(-rotSpeed) + OurPlayer.dirY * std::cos(-rotSpeed);
        }

        if (keys[SDL_SCANCODE_A]) {
            moveX -= -OurPlayer.dirY;
            moveY -= OurPlayer.dirX;
        }

        if (keys[SDL_SCANCODE_D]) {
            moveX += -OurPlayer.dirY;
            moveY += OurPlayer.dirX;
        }

        
        if (moveX != 0.0f || moveY != 0.0f) {
            float length = std::sqrt(moveX * moveX + moveY * moveY);
            moveX = (moveX / length) * OurPlayer.speed * deltaTime;
            moveY = (moveY / length) * OurPlayer.speed * deltaTime;

            float nextX = OurPlayer.posX + moveX;
            float nextY = OurPlayer.posY + moveY;

            float checkX = nextX + (moveX > 0 ? OurPlayer.PlayerRadius : -OurPlayer.PlayerRadius);
            if (settings::LoadedMap[(int)OurPlayer.posY * settings::LoadedMapWidth + (int)checkX] == 0.0f) OurPlayer.posX = nextX;

            float checkY = nextY + (moveY > 0 ? OurPlayer.PlayerRadius : -OurPlayer.PlayerRadius);
            if (settings::LoadedMap[(int)checkY * settings::LoadedMapWidth + (int)OurPlayer.posX] == 0.0f) OurPlayer.posY = nextY; 
        }
        

        std::fill(pixelBuffer.begin(), pixelBuffer.end(), 0x000000FF);
  
  
        // MY FUNCTION
        RenderWalls(&OurPlayer, pixelBuffer.data());
        
        SDL_UpdateTexture(texture, NULL, pixelBuffer.data(), settings::ScreenWidth * sizeof(uint32_t));

        // Draw Frame using explicit SDL3 APIs
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture, NULL, NULL); // SDL_RenderCopy changed to SDL_RenderTexture in SDL3
        SDL_RenderPresent(renderer);
    }

    // Clean up allocated memory structures
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


