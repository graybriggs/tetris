
#include "block.h"

Block::Block() :
	box({ 0, 0, BLOCK_WIDTH, BLOCK_HEIGHT }),
	block_color(BlockColor::EMPTY),
	block_pos(0,0)
{
}

Block::Block(BlockCoords coords) :
	box({ 0, 0, BLOCK_WIDTH, BLOCK_HEIGHT }),
	block_color(BlockColor::EMPTY),
	block_pos(coords)
{
}

Block::Block(BlockColor block_col, BlockCoords coords) :
	box({ 0, 0, BLOCK_WIDTH, BLOCK_HEIGHT }),
	block_color(block_col),
	block_pos(coords)
{
}

void Block::set_block_color(BlockColor bc) {
	block_color = bc;
}



BlockCoords Block::get_block_pos() {
	return block_pos;
}

void Block::set_block_pos(BlockCoords bc) {
	block_pos.x = bc.x;
	block_pos.y = bc.y;
}

void Block::set_block_pos(int x, int y) {
	block_pos.x = x;
	block_pos.y = y;
}

bool Block::horizontal_collision() {

	if (block_pos.x <= 0 || block_pos.x > 10)
		return true;
	
	return false;
}


void Block::render_block(SDL_Renderer* renderer) {

	SDL_Rect r = { block_pos.x * BLOCK_WIDTH, block_pos.y * BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT };

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
