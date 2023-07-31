
#include <algorithm>
#include <iostream>
#include <cstdlib>

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
	
	
	int choice = rand() % 5;
	if (choice == 0) {
		current_selected_shape = Shape::SQUARE;
	}
	else if (choice == 1) {
		current_selected_shape = Shape::LEFT_LSHAPE;
	}
	else if (choice == 2) {
		current_selected_shape = Shape::RIGHT_LSHAPE;
	}
	else if (choice == 3) {
		current_selected_shape = Shape::LINE;
	}
	else if (choice == 4) {
		current_selected_shape = Shape::TSHAPE;
	}
	

	if (current_selected_shape == Shape::SQUARE) {
		std::copy(std::begin(square), std::end(square), std::back_inserter(current_shape_blocks));
	}
	else if (current_selected_shape == Shape::LEFT_LSHAPE) {
		std::copy(std::begin(left_lshape), std::end(left_lshape), std::back_inserter(current_shape_blocks));
	}
	else if (current_selected_shape == Shape::RIGHT_LSHAPE) {
		std::copy(std::begin(right_lshape), std::end(right_lshape), std::back_inserter(current_shape_blocks));
	}
	else if (current_selected_shape == Shape::LINE) {
		std::copy(std::begin(line), std::end(line), std::back_inserter(current_shape_blocks));
	}
	else if (current_selected_shape == Shape::TSHAPE) {
		std::copy(std::begin(tshape), std::end(tshape), std::back_inserter(current_shape_blocks));
	}
}



void Shapes::move_down() {

	for (auto& b : current_shape_blocks) {
		b.update_position_offset(0, 1);
	}
}

void Shapes::move_left() {

	for (auto& b : current_shape_blocks) {
		b.update_position_offset(-1, 0);
	}
}

void Shapes::move_right() {

	for (auto& b : current_shape_blocks) {
		b.update_position_offset(1, 0);
	}
}

void Shapes::rotate_shape() {

	rotation_num++;
	if (rotation_num > 4) {
		rotation_num = 0;
	}
	// square - do nothing
	if (current_selected_shape == Shape::LEFT_LSHAPE) {

	}
	else if (current_selected_shape == Shape::RIGHT_LSHAPE) {

	}
	else if (current_selected_shape == Shape::LINE) {
		if (rotation_num == 0 || rotation_num == 2) {
			current_shape_blocks[0].set_blockcoords(BlockCoords(0, -1));
			current_shape_blocks[1].set_blockcoords(BlockCoords(0, 0));
			current_shape_blocks[2].set_blockcoords(BlockCoords(0, 1));
			current_shape_blocks[3].set_blockcoords(BlockCoords(0, 2));
		}
		else {
			current_shape_blocks[0].set_blockcoords(BlockCoords(-2, 0));
			current_shape_blocks[1].set_blockcoords(BlockCoords(-1, 0));
			current_shape_blocks[2].set_blockcoords(BlockCoords(-0, 0));
			current_shape_blocks[3].set_blockcoords(BlockCoords(1, 0));
		}
	}
	else if (current_selected_shape == Shape::TSHAPE) {
		if (rotation_num == 0) {
			current_shape_blocks[0].set_blockcoords(BlockCoords(0, -1));
			current_shape_blocks[1].set_blockcoords(BlockCoords(-1, 0));
			current_shape_blocks[2].set_blockcoords(BlockCoords(0, 0));
			current_shape_blocks[3].set_blockcoords(BlockCoords(1, 0));
		}
		else if (rotation_num == 1) {
			current_shape_blocks[0].set_blockcoords(BlockCoords(0, 0));
			current_shape_blocks[1].set_blockcoords(BlockCoords(0, 0));
			current_shape_blocks[2].set_blockcoords(BlockCoords(1, 0));
			current_shape_blocks[3].set_blockcoords(BlockCoords(0, 0));
		}
		else if (rotation_num == 2) {
			current_shape_blocks[0].set_blockcoords(BlockCoords(0, 1));
			current_shape_blocks[1].set_blockcoords(BlockCoords(-1, 0));
			current_shape_blocks[2].set_blockcoords(BlockCoords(0, 0));
			current_shape_blocks[3].set_blockcoords(BlockCoords(1, 0));
		}
		else if (rotation_num == 3) {
			current_shape_blocks[0].set_blockcoords(BlockCoords(0, 0));
			current_shape_blocks[1].set_blockcoords(BlockCoords(0, 0));
			current_shape_blocks[2].set_blockcoords(BlockCoords(-1, 0));
			current_shape_blocks[3].set_blockcoords(BlockCoords(0, 0));
		}
	}
}

void Shapes::set_current_selected_shape(Shape sh) {
	current_selected_shape = sh;
}

/*
Shape& Shapes::get_current_selected_shape() {
	return get_current_selected_shape;
}
*/


void Shapes::render_shape(SDL_Renderer* renderer) {

	for (auto& b : current_shape_blocks) {
		b.pos_to_grid();
		b.render_block(renderer);
	}

}