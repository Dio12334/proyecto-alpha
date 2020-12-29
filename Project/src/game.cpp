/*#include"game.h"

Game::Game(): mWindow(nullptr), 
    mRenderer(nullptr), 
    mTicksCount(0), 
    mIsRunning(true){}

bool Game::Initialize(){
  int sdlResult = SDL_Init(SDL_INIT_VIDEO);
  if(sdlResult != 0){
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  }

  mWindow = SDL_CreateWindow(
          "Proyecto sin nombre",
          100,
          100,
          1024,
          768,
          SDL_WINDOW_RESIZABLE
          );
  if(!mWindow){
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }
  mRenderer = SDL_CreateRenderer(
            mWindow,
            -1,
            SDL_RENDERER_ACCELERATED 
          );
  if(!mRenderer){
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }
}

void Game::RunLoop(){
  while(mIsRunning){
    ProcessInput();
    UpdateGame();
    GenerateOutput();
  }
}

void Game::ProcessInput(){}

void Game::UpdateGame(){}

void Game::GenerateOutput(){}

void Game::Shutdown(){
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}*/
