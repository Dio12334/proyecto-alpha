#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

void Dibujar_tableros(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 17, 71, 1);
	SDL_Rect tablero1 = { 100,250,550,550 };
	SDL_RenderFillRect(renderer, &tablero1);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	SDL_RenderDrawLine(renderer, 100, 250, 100, 800);
	SDL_RenderDrawLine(renderer, 650, 250, 650, 800);
	SDL_RenderDrawLine(renderer, 100, 250, 650, 250);
	SDL_RenderDrawLine(renderer, 100, 800, 650, 800);
	for (int i = 1; i < 10; i++) {
		int y1 = 250 + i * 55;
		SDL_RenderDrawLine(renderer, 100, y1, 650, y1);
	}
	for (int i = 1; i < 10; i++) {
		int x1 = 100 + i * 55;
		SDL_RenderDrawLine(renderer, x1, 250, x1, 800);
	}

	SDL_SetRenderDrawColor(renderer, 0, 17, 71, 1);
	SDL_Rect tablero2 = { 950,250,550,550 };
	SDL_RenderFillRect(renderer, &tablero2);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	SDL_RenderDrawLine(renderer, 950, 250, 950, 800);
	SDL_RenderDrawLine(renderer, 1500, 250, 1500, 800);
	SDL_RenderDrawLine(renderer, 950, 250, 1500, 250);
	SDL_RenderDrawLine(renderer, 950, 800, 1500, 800);
	for (int i = 1; i < 10; i++) {
		int y1 = 250 + i * 55;
		SDL_RenderDrawLine(renderer, 950, y1, 1500, y1);
	}
	for (int i = 1; i < 10; i++) {
		int x1 = 950 + i * 55;
		SDL_RenderDrawLine(renderer, x1, 250, x1, 800);
	}
}

void Dibujar_ataque_1(SDL_Renderer* renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1);
	SDL_Rect tiro1 = { 951 + 55*(x-1),251 + 55*(y-1),54,54 };
	SDL_RenderFillRect(renderer, &tiro1);
}

void Dibujar_ataque_0(SDL_Renderer* renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	SDL_Rect tiro0 = { 951 + 55 * (x - 1),251 + 55 * (y - 1),54,54 };
	SDL_RenderFillRect(renderer, &tiro0);
}

void Dibujar_defensa_1(SDL_Renderer* renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1);
	SDL_Rect tiro1 = { 101 + 55 * (x - 1),251 + 55 * (y - 1),54,54 };
	SDL_RenderFillRect(renderer, &tiro1);
}

void Dibujar_defensa_0(SDL_Renderer* renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	SDL_Rect tiro0 = { 101 + 55 * (x - 1),251 + 55 * (y - 1),54,54 };
	SDL_RenderFillRect(renderer, &tiro0);
}


int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Battle_ship", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 33, 33, 33, 1);
	SDL_RenderClear(renderer);

	Dibujar_tableros(renderer);
	Dibujar_ataque_1(renderer, 1,2);
	Dibujar_ataque_0(renderer, 1, 5);
	Dibujar_defensa_1(renderer, 4, 6);
	Dibujar_defensa_0(renderer, 7, 8);
	
	SDL_SetRenderDrawColor(renderer, 33, 33, 33, 1);
	SDL_RenderPresent(renderer);

	bool running = true;
	SDL_Event event;
	while (running) //Game loop
	{

		while (SDL_PollEvent(&event)) { //Cierra ventana cuando clickeas "x"
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
