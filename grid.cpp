

#include "grid.h"


const int GRID_SIZE = 60;

void Grid::render_grid(SDL_Renderer* renderer) {



	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	for (int i = 0; i < 8 + 1; ++i) {
		SDL_RenderDrawLine(renderer, i * GRID_SIZE, 0, i * GRID_SIZE, 20 * GRID_SIZE); // vertical
		
	}

	for (int i = 0; i < 20; ++i) {
		
		SDL_RenderDrawLine(renderer, 0, i * GRID_SIZE, 8 * GRID_SIZE, i * GRID_SIZE); // horizontal	
	}



}

