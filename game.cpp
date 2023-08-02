
#include <cstdlib>
#include <iostream>
#include <memory>

#include "collision.h"
#include "shapes.h"
#include "game.h"
#include "grid.h"
#include "timer.h"

Game::Game() {
	grid = std::make_unique<Grid>();
	current_shape = std::make_unique<Shapes>();	

	vertical_timer = std::make_unique<Timer>(std::bind(&Shapes::move_down, current_shape.get()), 1000, true);
	horizontal_timer = std::make_unique<Timer>(nullptr, 200, false);
}

void Game::init_game() {

	current_shape->init_blocks();

	vertical_timer->start_timer();
	horizontal_timer->start_timer();
}

void Game::collision() {


}

void Game::input(SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		if (!horizontal_timer->is_active()) {
			if (event.key.keysym.sym == SDLK_LEFT) {
				current_shape->move_horizontal(-1);
				horizontal_timer->start_timer();
			}
			else if (event.key.keysym.sym == SDLK_RIGHT) {
				current_shape->move_horizontal(1);
				horizontal_timer->start_timer();
			}
			else if (event.key.keysym.sym == SDLK_UP) {
				current_shape->rotate_shape();
			}
		}
	}
}

void Game::update(float dt) {


	vertical_timer->update();
	horizontal_timer->update();

	std::vector<Block> sh = current_shape->get_current_shape();
	for (Block b : sh) {

	}
}

void Game::render(SDL_Renderer* renderer) {

	grid->render_blocks(renderer);
	current_shape->render_shape(renderer);
	grid->render_grid(renderer);

}