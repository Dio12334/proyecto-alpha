#include"game.h"

Game::Game(): mWindow(nullptr), 
    mRenderer(nullptr), 
    mTicksCount(0), 
    mIsRunning(true), 
    mUpdatingActors(false){}

bool Game::Initialize(){
  
  IMG_Init(IMG_INIT_PNG);

	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0){
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	
	
	mWindow = SDL_CreateWindow(
		"Game Programming in C++ (TEMPLATE)", // Window title
		100,	// Top left x-coordinate of window
		100,	// Top left y-coordinate of window
		1024,	// Width of window
		768,	// Height of window
		0		// Flags (0 for no flags set)
	);

	if (!mWindow){
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	
	//// Create SDL renderer
	mRenderer = SDL_CreateRenderer(
		mWindow, // Window to create renderer for
		-1,		 // Usually -1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer){
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}
  return true;
}

void Game::RunLoop(){

  while(mIsRunning){
    ProcessInput();
    UpdateGame();
    GenerateOutput();
  }

}

void Game::ProcessInput(){}
void Game::UpdateGame(){
  while(!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

  float deltaTime = (SDL_GetTicks() - mTicksCount)/1000.0f;

  if(deltaTime > 0.05f)
      deltaTime = 0.05f;

  mUpdatingActors = true;
  for(auto actor: mActors)
    actor->Update(deltaTime);
  mUpdatingActors = false;

  for(auto pending: mPendingActors)
      mActors.emplace_back(pending);
  mPendingActors.clear();

  std::vector<Actor*> deadActors;
  for(auto actor: mActors)
      if(actor->GetState() == Actor::EDead)
          deadActors.emplace_back(actor);

  for(auto actor: deadActors)
      delete actor;
  
}
void Game::GenerateOutput(){}

void Game::AddActor(class Actor* actor){

  if(mUpdatingActors)
    mPendingActors.emplace_back(actor);
  
  else
    mActors.emplace_back(actor);
  
}
void Game::RemoveActor(class Actor* actor){}

void Game::Shutdown(){

  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);  
  
  while(!mActors.empty())
      delete mActors.back();

  SDL_Quit();
}
