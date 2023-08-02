#pragma once

#include <memory>

#include <SDL.h>

//class Shapes;
#include "shapes.h"

class Grid;
class Timer;

class Game {
public:
	Game();
	void init_game();
	void input(SDL_Event event);
	void collision();
	void update(float dt);
	void render(SDL_Renderer* renderer);

private:
	std::unique_ptr<Grid> grid;
	std::unique_ptr<Shapes> current_shape;

	std::unique_ptr<Timer> horizontal_timer;
	std::unique_ptr<Timer> vertical_timer;
	

};