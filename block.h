#pragma once

#include <SDL.h>

#include "util.h"

class Block {
public:
	const int BLOCK_WIDTH = 60;
	const int BLOCK_HEIGHT = 60;
	
	enum class BlockColor { RED, GREEN, BLUE, YELLOW, PURPLE };


	Block(BlockColor block_col, BlockCoords pos);

	void move_block_down();
	void pos_to_grid();

	void render_block(SDL_Renderer*);


private:
	BlockCoords pos; // block's position in the grid
	BlockCoords position_offset; // control where the block is on the grids

	BlockColor block_color;
	SDL_Rect box;
};