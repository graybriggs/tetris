
#include "block.h"

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

void Block::update_position_offset(int x, int y) {
	
	block_pos_offset.x += x;
	block_pos_offset.y += y;
}

void Block::blockspace_to_gridspace() {

	box.x = block_pos.x * BLOCK_WIDTH + block_pos_offset.x * BLOCK_WIDTH;
	box.y = block_pos.y * BLOCK_HEIGHT + block_pos_offset.y * BLOCK_HEIGHT;
	
}


void Block::set_block_blockspace(int x, int y) {
	block_pos.x = x;
	block_pos.y = y;

	box.x = block_pos.y * BLOCK_WIDTH;
	box.y = block_pos.y * BLOCK_HEIGHT;
	box.w = BLOCK_WIDTH;
	box.h = BLOCK_HEIGHT;
}

void Block::set_block_blockspace(BlockCoords bc) {
	block_pos.x = bc.x;
	block_pos.y = bc.y;

	box.x = block_pos.y * BLOCK_WIDTH;
	box.y = block_pos.y * BLOCK_HEIGHT;
	box.w = BLOCK_WIDTH;
	box.h = BLOCK_HEIGHT;
}

SDL_Rect Block::get_block_gridspace() {
	SDL_Rect r;
	r.x = block_pos.x * BLOCK_WIDTH + block_pos_offset.x * BLOCK_WIDTH;
	r.y = block_pos.y * BLOCK_HEIGHT + block_pos_offset.y * BLOCK_HEIGHT;
	r.w = BLOCK_WIDTH;
	r.h = BLOCK_HEIGHT;

	return r;
}

BlockCoords Block::get_block_blockspace() {

	return block_pos;
}

void Block::render_block(SDL_Renderer* renderer) {

	SDL_Rect r = get_block_gridspace();

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
