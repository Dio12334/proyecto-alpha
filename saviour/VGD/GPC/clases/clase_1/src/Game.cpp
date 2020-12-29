/*
const int thickness = 15;
const float paddleH = 100.0f;

void Game::ProcessInput(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				mIsRunning = false;
				break;
		}
	}
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if(state[SDL_SCANCODE_ESCAPE]){
		mIsRunning = false;
	}
	// Update paddle direction based on W/S keys
	mPaddleDir = 0;
	if (state[SDL_SCANCODE_W])
	{
		mPaddleDir -= 1;
	}
	if (state[SDL_SCANCODE_S])
	{
		mPaddleDir += 1;
	}
	mPaddleDir2 = 0;
        if (state[SDL_SCANCODE_I])
        {
                mPaddleDir2 -= 1;
        }
        if (state[SDL_SCANCODE_K])
        {
                mPaddleDir2 += 1;
        }

}
void Game::UpdateGame(){
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
		;

	// Delta time is the difference in ticks from last frame
	// (converted to seconds)
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	
	// Clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	// Update tick counts (for next frame)
	mTicksCount = SDL_GetTicks();
	
	// Update paddle position based on direction
	if (mPaddleDir != 0)
	{
		mPaddlePos.y += mPaddleDir * 300.0f * deltaTime;
		// Make sure paddle doesn't move off screen!
		if (mPaddlePos.y < (paddleH/2.0f + thickness))
		{
			mPaddlePos.y = paddleH/2.0f + thickness;
		}
		else if (mPaddlePos.y > (768.0f - paddleH/2.0f - thickness))
		{
			mPaddlePos.y = 768.0f - paddleH/2.0f - thickness;
		}
	}

	// Update paddle position based on direction
        if (mPaddleDir2 != 0)
        {
                mPaddlePos2.y += mPaddleDir2 * 300.0f * deltaTime;
                // Make sure paddle doesn't move off screen!
                if (mPaddlePos2.y < (paddleH/2.0f + thickness))
                {
                        mPaddlePos2.y = paddleH/2.0f + thickness;
                }
                else if (mPaddlePos2.y > (768.0f - paddleH/2.0f - thickness))
                {
                        mPaddlePos2.y = 768.0f - paddleH/2.0f - thickness;
                }
        }
	
	// Update ball position based on ball velocity
	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime;
	
	// Bounce if needed
	// Did we intersect with the paddle?

	//float diff2 = mPaddlePos2.y - mBallPos.y;
        // Take absolute value of difference
        //diff2 = (diff2 > 0.0f) ? diff2 : -diff2;

	//if (
                // Our y-difference is small enough
        //        diff2 <= paddleH / 2.0f &&
                // We are in the correct x-position
        //        mBallPos.x >= 1024.0f-25.0f && mBallPos.x <= 1024.0f-20.0f &&
                // The ball is moving to the left
        //        mBallVel.x < 0.0f)
        //{
         //       mBallVel.x *= -1.0f;
        //}


	float diff = mPaddlePos.y - mBallPos.y;
        // Take absolute value of difference
        diff = (diff > 0.0f) ? diff : -diff;

	 if (
		// Our y-difference is small enough
		diff <= paddleH / 2.0f &&
		// We are in the correct x-position
		mBallPos.x <= 25.0f && mBallPos.x >= 20.0f &&
		// The ball is moving to the right
		mBallVel.x > 0.0f)
	{
		mBallVel.x *= -1.0f;
	}
	// Did the ball go off the screen? (if so, end game)
	else if (mBallPos.x <= 0.0f )
	{
		mIsRunning = false;
	}
	
	// Did the ball collide with the top wall?
	if (mBallPos.y <= thickness && mBallVel.y < 0.0f)
	{
		mBallVel.y *= -1;
	}
	// Did the ball collide with the bottom wall?
	else if (mBallPos.y >= (768 - thickness) &&
		mBallVel.y > 0.0f)
	{
		mBallVel.y *= -1;
	}
        
}
void Game::GenerateOutput(){
	
	SDL_SetRenderDrawColor(
				mRenderer,
				0, //R
				0, //G
				255, //B
				255 //A
			);
	SDL_RenderClear(mRenderer);

	//top wall

	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255 );
	SDL_Rect wall{
		0, // Top left x
		0, // Top left y
		1024, // width
		thickness //height
	};
	SDL_RenderFillRect(mRenderer, &wall);

	// botoom wall
	wall.y = 768 - thickness;
        SDL_RenderFillRect(mRenderer, &wall);


	//right wall
	//wall.x = 1024 - thickness;
	//wall.y = 0;
	//wall.w = thickness;
	//wall.h = 1024;
	//SDL_RenderFillRect(mRenderer, &wall);

// Draw paddle
 	SDL_Rect paddle{
 			static_cast<int>(mPaddlePos.x),
 			static_cast<int>(mPaddlePos.y - paddleH/2),
 			thickness,
 			static_cast<int>(paddleH)
 	};
 	SDL_RenderFillRect(mRenderer, &paddle);
 	
	SDL_Rect paddle2{
                        static_cast<int>(mPaddlePos2.x),
                        static_cast<int>(mPaddlePos2.y - paddleH/2),
                        thickness,
                        static_cast<int>(paddleH)
        };
        SDL_RenderFillRect(mRenderer, &paddle2);

 	// Draw ball
 	SDL_Rect ball{	
 			static_cast<int>(mBallPos.x - thickness/2),
 			static_cast<int>(mBallPos.y - thickness/2),
 			thickness,
 			thickness 													
	};
	SDL_RenderFillRect(mRenderer, &ball);

	SDL_RenderPresent(mRenderer);


}

Game::Game(){
	mWindow = nullptr;
	mRenderer = nullptr;
	mTicksCount = 0;
	mIsRunning = true;
}

bool Game::Initialize(){
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if(sdlResult != 0){
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	mWindow = SDL_CreateWindow(
			"Game Programming in c++ (Chapter 1)", //window title
			100, //Top left x-coordinates of window
			100, // Top left y-coordinate of window
			1024, // Width of window
			768, // Height of window
			0  //Flags (0 for no flag set)
			);
	if(!mWindow){
		SDL_Log("Failed to create a window: %s", SDL_GetError());
		return false;
	}
	mRenderer = SDL_CreateRenderer(
				mWindow, //window to create the renderer for
				-1, //Usually -1
				SDL_RENDERER_ACCELERATED 
			);
        if(!mRenderer){
                SDL_Log("Renderer failed to initialize: %s", SDL_GetError());
                return false;
        }
	mPaddlePos.x = 10.0f;
	mPaddlePos.y = 768.0f/2.0f;
	        
	mPaddlePos2.x = 1024.0f - (thickness+10);
        mPaddlePos2.y = 768.0f/2.0f;

	mBallPos.x = 1024.0f/2.0f;
	mBallPos.y = 768.0f/2.0f;
	mBallVel.x = -200.0f;
	mBallVel.y = 235.0f;
	return true;
}

void Game::RunLoop(){
	while(mIsRunning){
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown(){
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
}
*/
