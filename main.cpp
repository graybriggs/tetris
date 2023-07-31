
#include <SDL.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <utility>

#include "block.h"
#include "game.h"
#include "grid.h"
#include "globals.h"
#include "shapes.h"
#include "timer.h"

void foo() {
	fprintf(stdout, "tick\n");
}

int main(int argc, char* args[]) {

	srand(time(nullptr));
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	SDL_Window* window = window = SDL_CreateWindow(
		"Tetris Ripoff",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		global::SCREEN_W,
		global::SCREEN_H,
		SDL_WINDOW_SHOWN
	);

	Uint32 rendererFlags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, rendererFlags);


	auto game = std::make_unique<Game>();
	game->init_game();

	bool done = false;

	SDL_Event event;

	constexpr float fps = 60.0f;
	constexpr float dt = 1.0f / fps;
	float accumulator = 0.0f;
	float frameStart = SDL_GetTicks();



	while (!done) {
		const float currentTime = SDL_GetTicks();
		accumulator += currentTime - frameStart;
		frameStart = currentTime;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = true;
			}

			game->input(event);
		}

		if (accumulator > 0.2f)
			accumulator = 0.2f;

		
		while (accumulator > dt) {

			// logic
			game->update(dt);

			accumulator -= dt;

		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
		SDL_RenderClear(renderer);

		game->render(renderer);

		SDL_RenderPresent(renderer);

	}


	return 0;
}