
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "grid.h"
#include "shapes.h"

Shapes::Shapes() :
	rotation_num(0)
{
	current_selected_shape = Shape::TSHAPE;
}

void Shapes::init_blocks() {

	// Square - 0 rotations

	square.push_back(Block(Block::BlockColor::GREEN, BlockCoords(-1, -1)));
	square.push_back(Block(Block::BlockColor::GREEN, BlockCoords(0, -1)));
	square.push_back(Block(Block::BlockColor::GREEN, BlockCoords(-1, 0)));
	square.push_back(Block(Block::BlockColor::GREEN, BlockCoords(0, 0)));

	// left l-shape - 4 rotations

	left_lshape.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(0, -1)));
	left_lshape.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(0, 0)));
	left_lshape.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(0, 1)));
	left_lshape.push_back(Block(Block::BlockColor::YELLOW, BlockCoords(-1, 1)));

	// right l-shape - 4 rotations


	right_lshape.push_back(Block(Block::BlockColor::RED, BlockCoords(-1, -1)));
	right_lshape.push_back(Block(Block::BlockColor::RED, BlockCoords(-1, 0)));
	right_lshape.push_back(Block(Block::BlockColor::RED, BlockCoords(-1, 1)));
	right_lshape.push_back(Block(Block::BlockColor::RED, BlockCoords(0, 1)));

	// line - 2 rotations

	line.push_back(Block(Block::BlockColor::PURPLE, BlockCoords(0, -1)));
	line.push_back(Block(Block::BlockColor::PURPLE, BlockCoords(0, 0)));
	line.push_back(Block(Block::BlockColor::PURPLE, BlockCoords(0, 1)));
	line.push_back(Block(Block::BlockColor::PURPLE, BlockCoords(0, 2)));

	// T-shape - 4 rotations

	tshape.push_back(Block(Block::BlockColor::BLUE, BlockCoords(0, -1)));
	tshape.push_back(Block(Block::BlockColor::BLUE, BlockCoords(-1, 0)));
	tshape.push_back(Block(Block::BlockColor::BLUE, BlockCoords(0, 0)));
	tshape.push_back(Block(Block::BlockColor::BLUE, BlockCoords(1, 0)));

	// left z

	zleft.push_back(Block(Block::BlockColor::CYAN, BlockCoords(-1, 0)));
	zleft.push_back(Block(Block::BlockColor::CYAN, BlockCoords(0, 0)));
	zleft.push_back(Block(Block::BlockColor::CYAN, BlockCoords(0, 1)));
	zleft.push_back(Block(Block::BlockColor::CYAN, BlockCoords(1, 1)));

	// right z

	zright.push_back(Block(Block::BlockColor::WHITE, BlockCoords(-1, 1)));
	zright.push_back(Block(Block::BlockColor::WHITE, BlockCoords(0, 1)));
	zright.push_back(Block(Block::BlockColor::WHITE, BlockCoords(0, 0)));
	zright.push_back(Block(Block::BlockColor::WHITE, BlockCoords(1, 0)));

	get_next_shape();
}

void Shapes::move_down() {
	
	if (!vertical_collision()) {
		for (auto& b : current_shape_blocks) {
			BlockCoords bc = b.get_block_pos();
			bc.y++;
			b.set_block_pos(bc);
		}
	}
	else {
		get_next_shape();
	}
}


void Shapes::move_horizontal(int amount) {
	
	if (!horizontal_collision()) {
		for (auto& b : current_shape_blocks) {
			BlockCoords bc = b.get_block_pos();
			bc.x += amount;
			b.set_block_pos(bc);
		}
	}
}


void Shapes::rotate_shape() {

	rotation_num++;
	if (rotation_num > 4) {
		rotation_num = 0;
	}
}

void Shapes::set_current_selected_shape(Shape sh) {
	current_selected_shape = sh;
}


std::vector<Block> Shapes::get_current_shape() {
	return current_shape_blocks;
}

void Shapes::get_next_shape() {

	current_shape_blocks.clear();
	int choice = rand() % 7;
	if (choice == 0) {
		current_selected_shape = Shape::SQUARE;
		std::copy(std::begin(square), std::end(square), std::back_inserter(current_shape_blocks));
	}
	else if (choice == 1) {
		current_selected_shape = Shape::LEFT_LSHAPE;
		std::copy(std::begin(left_lshape), std::end(left_lshape), std::back_inserter(current_shape_blocks));
	}
	else if (choice == 2) {
		current_selected_shape = Shape::RIGHT_LSHAPE;
		std::copy(std::begin(right_lshape), std::end(right_lshape), std::back_inserter(current_shape_blocks));
	}
	else if (choice == 3) {
		current_selected_shape = Shape::LINE;
		std::copy(std::begin(line), std::end(line), std::back_inserter(current_shape_blocks));
	}
	else if (choice == 4) {
		current_selected_shape = Shape::TSHAPE;
		std::copy(std::begin(tshape), std::end(tshape), std::back_inserter(current_shape_blocks));
	}
	else if (choice == 5) {
		current_selected_shape = Shape::ZLEFT;
		std::copy(std::begin(zleft), std::end(zleft), std::back_inserter(current_shape_blocks));
	}
	else if (choice == 6) {
		current_selected_shape = Shape::ZRIGHT;
		std::copy(std::begin(zright), std::end(zright), std::back_inserter(current_shape_blocks));
	}
}

bool Shapes::horizontal_collision() {

	for (auto& b : current_shape_blocks) {
		if (b.get_block_pos().x <= 0|| b.get_block_pos().x > GRID_COLUMNS)
			return true;
	}

	return false;
}

bool Shapes::vertical_collision() {

	for (auto& b : current_shape_blocks) {
		if (b.get_block_pos().y > GRID_ROWS)
			return true;
	}

	return false;
}

void Shapes::render_shape(SDL_Renderer* renderer) {

	for (auto& b : current_shape_blocks) {
		b.render_block(renderer);
	}

}