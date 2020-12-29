#ifndef GAME_H
#define GAME_H

#include<SDL2/SDL.h>
#include<vector>

class Game{

	struct Vector2{
		float x;
		float y;
	};

	struct Ball{
		Vector2 pos;
		Vector2 vel;
	};
	public:
		Game();
		//initialize the game
		bool Initialize();
		//Runs the game loop until the game is over
		void RunLoop();
		//shutdown the game
		void Shutdown();
	private:
		//Helper functions for the game loop
		void ProcessInput();
		void UpdateGame();
		void GenerateOutput();
		
		//window created by SDL
		SDL_Window* mWindow;
		//Game should continue to run
		bool mIsRunning;
		//Renderer
		SDL_Renderer* mRenderer;

		Uint32 mTicksCount;

		Vector2 mPaddlePos;
		
		Vector2 mPaddlePos2;

		Vector2 mBallPos;

		int mPaddleDir;

		int mPaddleDir2;

		Vector2 mBallVel;

		std::vector<Ball> Balls;
};

#endif
