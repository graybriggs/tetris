
#include <iostream>
#include "shapes.h"

void Shapes::init_blocks() {

	// Square

	square.push_back(Block(Block::BlockColor::GREEN, BlockCoords(0, 0)));
	square.push_back(Block(Block::BlockColor::GREEN, BlockCoords(1, 0)));
	square.push_back(Block(Block::BlockColor::GREEN, BlockCoords(0, 1)));
	square.push_back(Block(Block::BlockColor::GREEN, BlockCoords(1, 1)));

	// left l-shape


	left_lshape.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(1, 0)));
	left_lshape.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(1, 1)));
	left_lshape.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(1, 2)));
	left_lshape.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(0, 2)));

	// right l-shape


	right_lshape.push_back(Block(Block::BlockColor::RED, BlockCoords(0, 0)));
	right_lshape.push_back(Block(Block::BlockColor::RED, BlockCoords(0, 1)));
	right_lshape.push_back(Block(Block::BlockColor::RED, BlockCoords(0, 2)));
	right_lshape.push_back(Block(Block::BlockColor::RED, BlockCoords(1, 2)));

	// line

	line.push_back(Block(Block::BlockColor::PURPLE, BlockCoords(1, 0)));
	line.push_back(Block(Block::BlockColor::PURPLE, BlockCoords(1, 1)));
	line.push_back(Block(Block::BlockColor::PURPLE, BlockCoords(1, 2)));
	line.push_back(Block(Block::BlockColor::PURPLE, BlockCoords(1, 3)));

	// T-shape

	tshape.push_back(Block(Block::BlockColor::BLUE, BlockCoords(1, 0)));
	tshape.push_back(Block(Block::BlockColor::BLUE, BlockCoords(0, 1)));
	tshape.push_back(Block(Block::BlockColor::BLUE, BlockCoords(1, 1)));
	tshape.push_back(Block(Block::BlockColor::BLUE, BlockCoords(2, 1)));

}


void Shapes::move_down() {

	std::cout << "test" << std::endl;

	for (auto& b : tshape) {
		b.move_block_down();
	}

}


void Shapes::render_shape(SDL_Renderer* renderer, Shape shape) {

	switch (shape) {
	case Shape::SQUARE:
		for (auto& b : square) {
			b.pos_to_grid();
			b.render_block(renderer);
		}
		break;
	case Shape::LEFT_LSHAPE:
		for (auto& b : left_lshape) {
			b.pos_to_grid();
			b.render_block(renderer);
		}
		break;
	case Shape::RIGHT_LSHAPE:
		for (auto& b : right_lshape) {
			b.pos_to_grid();
			b.render_block(renderer);
		}
		break;
	case Shape::LINE:
		for (auto& b : line) {
			b.pos_to_grid();
			b.render_block(renderer);
		}
		break;
	case Shape::TSHAPE:
		for (auto& b : tshape) {
			b.pos_to_grid();
			b.render_block(renderer);
		}

		break;
	}

}