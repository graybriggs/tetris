

#include "grid.h"

#include "block.h"

const int GRID_SIZE = 40;

Grid::Grid() {
	int x = 0;
	int y = 0;
	for (int i = 0; i < GRID_ROWS * GRID_COLUMNS; ++i) {
		if (x >= GRID_COLUMNS) {
			x = 0;
			y += STEP;
		}
		grid.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(x,y)));
		++x;
	}
}

int Grid::to1d(int x, int y) {

	return y * GRID_ROWS + x;
}

void Grid::render_blocks(SDL_Renderer* renderer) {


	for (auto& b : grid) {
		
		b.render_block(renderer);
	}

}

void Grid::render_grid(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	for (int i = 0; i < 8 + 1; ++i) {
		SDL_RenderDrawLine(renderer, i * GRID_SIZE, 0, i * GRID_SIZE, 20 * GRID_SIZE); // vertical
	}

	for (int i = 0; i < 18; ++i) {
		
		SDL_RenderDrawLine(renderer, 0, i * GRID_SIZE, 8 * GRID_SIZE, i * GRID_SIZE); // horizontal	
	}
}

