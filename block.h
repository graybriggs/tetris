#pragma once

#include <SDL.h>

#include "util.h"

class Block {
public:
	const int BLOCK_WIDTH = 40;
	const int BLOCK_HEIGHT = 40;
	BlockCoords BLOCK_OFFSET = BlockCoords(5,0);
	
	enum class BlockColor { RED, GREEN, BLUE, YELLOW, PURPLE, EMPTY };

	Block();
	Block(BlockCoords);
	Block(BlockColor block_col, BlockCoords pos);

	void set_block_color(BlockColor);

	BlockCoords get_block_pos();
	void set_block_pos(BlockCoords);
	void set_block_pos(int x, int y);

	bool horizontal_collision();
	bool vertical_collision();

	void render_block(SDL_Renderer*);


private:
	BlockCoords block_pos; // block's position in the grid
	
	//BlockCoords block_pos_offset; // control where the block is on the grids

	BlockColor block_color;
	SDL_Rect box;
};