
#include "block.h"

Block::Block() :
	block_rect({ 0, 0, BLOCK_WIDTH, BLOCK_HEIGHT }),
	block_color(BlockColor::EMPTY)
{
	block_rect = { .x = 0, .y = 0, .w = BLOCK_WIDTH, .h = BLOCK_HEIGHT };
}

Block::Block(int xpos, int ypos):
	block_color(BlockColor::EMPTY)
{
	block_rect = {
		.x = xpos + BLOCK_OFFSET_X,
		.y = ypos + BLOCK_OFFSET_Y,
		.w = BLOCK_WIDTH,
		.h = BLOCK_HEIGHT
	};
}


Block::Block(BlockColor block_col, int xpos, int ypos):
	block_color(block_col)
{
	block_rect = {
		.x = xpos + BLOCK_OFFSET_X,
		.y = ypos + BLOCK_OFFSET_Y,
		.w = BLOCK_WIDTH,
		.h = BLOCK_HEIGHT
	};
}

Block& Block::operator=(const Block& rhs) {
	Block b;
	posx = rhs.posx;
	posy = rhs.posy;
	block_color = rhs.block_color;
	block_rect = rhs.block_rect;
	return b;
}

void Block::set_block_color(BlockColor bc) {
	block_color = bc;
}

Block::BlockColor Block::get_block_color() {
	return block_color;
}

SDL_Rect Block::get_block_pos() {
	return block_rect;
}


void Block::set_block_pos(int x, int y) {
	block_rect.x = x;
	block_rect.y = y;
}

Block Block::get_block() {
	return *this;
}

bool Block::horizontal_collision() {

	if (block_rect.x < 0 || block_rect.x > 10)
		return true;
	
	return false;
}

bool Block::vertical_collision() {

	if (block_rect.y >= 15)
		return true;

	return false;
}

void Block::render_block(SDL_Renderer* renderer) {

	SDL_Rect r = { block_rect.x * BLOCK_WIDTH, block_rect.y * BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT };

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
	case BlockColor::CYAN:
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		SDL_RenderFillRect(renderer, &r);
		break;
	case BlockColor::WHITE:
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &r);
		break;
	}
}
