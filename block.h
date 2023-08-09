#pragma once

#include <SDL.h>

#include "util.h"

class Block {
public:
	const int BLOCK_WIDTH = 40;
	const int BLOCK_HEIGHT = 40;
	int BLOCK_OFFSET_X = 5;
	int BLOCK_OFFSET_Y = 0;
	
	enum class BlockColor { RED, GREEN, BLUE, YELLOW, PURPLE, CYAN, WHITE, EMPTY };

	Block();
	Block(int xpos, int ypos);
	Block(BlockColor block_col, int xpos, int ypos);

	void set_block_color(BlockColor);

	SDL_Rect get_block_pos();
	void set_block_pos(int x, int y);

	Block get_block();
	BlockColor get_block_color();

	bool horizontal_collision();
	bool vertical_collision();

	void render_block(SDL_Renderer*);


private:
	//BlockCoords block_pos; // block's position in the grid
	
	//BlockCoords block_pos_offset; // control where the block is on the grids
	int posx, posy;
	BlockColor block_color;
	SDL_Rect block_rect;
};