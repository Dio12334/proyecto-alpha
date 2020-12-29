#ifndef GAME_H
#define GAME_H

#include"lib.h"
#include"actor.h"

class Game{
  private:

      void ProcessInput();
      void UpdateGame();
      void GenerateOutput();

      SDL_Window* mWindow;
      SDL_Renderer* mRenderer;
      Uint32 mTicksCount;
      bool mIsRunning, mUpdatingActors;

      std::vector<class Actor*> mActors, mPendingActors;

      void AddActor(class Actor* actor);
      void RemoveActor(class Actor* actor);
  public:
      Game();
      bool Initialize();
      void RunLoop();
      void Shutdown();

};

#endif
