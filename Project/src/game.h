#ifndef GAME_H
#define GAME_H

#include"libs/lib.h"
#include"world/world.h"
#include"world/world.cpp"
#include"world/slot.cpp"

class Game{
  private:

      void ProcessInput();
      void UpdateGame();
      void GenerateOutput();

      SDL_Window* mWindow;
      SDL_Renderer* mRenderer;
      Uint32 mTicksCount;
      bool mIsRunning;

      World *mundo;

  public:
      Game();
      bool Initialize();
      void RunLoop();
      void Shutdown();

};

#endif
