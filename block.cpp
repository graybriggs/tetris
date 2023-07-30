
#include "block.h"

Block::Block(BlockColor block_col, BlockCoords coords) :
	box({ 0, 0, BLOCK_WIDTH, BLOCK_HEIGHT }),
	block_color(block_col),
	pos(coords)
{

	
}


void Block::pos_to_grid() {

	box.x = pos.x * BLOCK_WIDTH + position_offset.x;
	box.y = pos.y * BLOCK_HEIGHT + position_offset.y;
	
}

void Block::render_block(SDL_Renderer* renderer) {

	SDL_Rect r = box;

	switch (block_color) {
	case BlockColor::RED:
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &r);
		break;
	case BlockColor::BLUE:
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderFillRect(renderer, &r);
		break;
	case BlockColor::GREEN:
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &r);
		break;
	case BlockColor::YELLOW:
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		SDL_RenderFillRect(renderer, &r);
		break;
	case BlockColor::PURPLE:
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderFillRect(renderer, &r);
		break;
	}
}
