#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
#include "Game.h"


Game::Game() {
    isRunning = true;
};

Game::~Game() {
    // Logger::Log("Game destructor called")
};

void Game::Initialize() {


    // Initialize the SDL Controller
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return;
    }

    SDL_DisplayMode displayMode;
    SDL_Window window =
    SDL_SetWindowDisplayMode(window*, displayMode);
    SDL_Renderer renderer;
    

}