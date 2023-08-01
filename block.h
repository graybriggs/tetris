#pragma once

#include <SDL.h>

#include "util.h"

class Block {
public:
	const int BLOCK_WIDTH = 40;
	const int BLOCK_HEIGHT = 40;
	
	enum class BlockColor { RED, GREEN, BLUE, YELLOW, PURPLE, EMPTY };

	Block(BlockCoords);
	Block(BlockColor block_col, BlockCoords pos);

	void update_position_offset(int x, int y);
	void blockspace_to_gridspace();
	void render_block(SDL_Renderer*);


	void set_block_blockspace(int x, int y);
	void set_block_blockspace(BlockCoords);

	SDL_Rect get_block_gridspace();
	BlockCoords get_block_blockspace();


private:
	BlockCoords block_pos; // block's position in the grid
	BlockCoords block_pos_offset; // control where the block is on the grids

	BlockColor block_color;
	SDL_Rect box;
};