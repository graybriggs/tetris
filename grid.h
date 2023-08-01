#pragma once

#include <SDL.h>

#include <vector>

#include "util.h"

/*

Grid is composed of blocks

Two spaces, grid space and block space:
grid space is the standard screen space where one pixel is size 1 on the screen

Block space is the space of the Tetris blocks, here 60x60 on a grid that is size 10x20

Create functions to seemlessly convert between the two spaces.

The game will work in block space

*/


constexpr int GRID_COLUMNS = 10;
constexpr int GRID_ROWS = 18;
constexpr int STEP = 40; // STEP is the equivalent of a block width or height

class Block;

class Grid {
public:

	Grid();
	
	SDL_Rect block_to_grid(BlockCoords bc);

	void render_blocks(SDL_Renderer* renderer);
	void render_grid(SDL_Renderer* renderer);
	int to1d(int x, int y);

private:

	std::vector<Block> grid;

};