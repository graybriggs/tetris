
#include <cstdlib>
#include <memory>

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
	current_shape->move_right();
	current_shape->move_right();

	vertical_timer->start_timer();
	horizontal_timer->start_timer();
}

void Game::input(SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		if (!horizontal_timer->is_active()) {
			if (event.key.keysym.sym == SDLK_LEFT) {
				current_shape->move_left();
				horizontal_timer->start_timer();
			}
			else if (event.key.keysym.sym == SDLK_RIGHT) {
				current_shape->move_right();
				horizontal_timer->start_timer();
			}
		}
	}
}

void Game::update(float dt) {

	vertical_timer->update();
	horizontal_timer->update();
}

void Game::render(SDL_Renderer* renderer) {
	//b.pos_to_grid();
	//b.render_block(renderer);
	current_shape->render_shape(renderer);
	grid->render_grid(renderer);
}