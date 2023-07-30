#pragma once

#include <array>
#include <vector>

#include "block.h"

// technically called Tetromino - geometric shape composed of four squares, connected orthogonally
class Shapes {
public:

	enum class Shape { SQUARE, LEFT_LSHAPE, RIGHT_LSHAPE, LINE, TSHAPE, };

	void init_blocks();
	void move_down();

	void render_shape(SDL_Renderer*, Shape);

private:

	//std::array<Block, 4> shape;
	std::vector<Block> square;
	std::vector<Block> left_lshape;
	std::vector<Block> right_lshape;
	std::vector<Block> line;
	std::vector<Block> tshape;
};