
#include <SDL.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

#include "block.h"
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


	auto grid = std::make_unique<Grid>();
	BlockCoords c;
	c.x = 1;
	c.y = 1;
	Block b(Block::BlockColor::RED, c);

	Shapes s;
	s.init_blocks();

	bool done = false;

	SDL_Event event;

	constexpr float fps = 60.0f;
	constexpr float dt = 1.0f / fps;
	float accumulator = 0.0f;
	float frameStart = SDL_GetTicks();


	Timer timer(foo, 500, true);
	timer.start_timer();

	while (!done) {
		const float currentTime = SDL_GetTicks();
		accumulator += currentTime - frameStart;
		frameStart = currentTime;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = true;
			}
		}

		if (accumulator > 0.2f)
			accumulator = 0.2f;

		timer.update();
		while (accumulator > dt) {

			// logic
			

			accumulator -= dt;

		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
		SDL_RenderClear(renderer);


		//b.pos_to_grid();
		//b.render_block(renderer);
		s.render_shape(renderer, Shapes::Shape::TSHAPE);


		grid->render_grid(renderer);

		SDL_RenderPresent(renderer);

	}


	return 0;
}