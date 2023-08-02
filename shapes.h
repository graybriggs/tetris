#pragma once

#include <array>
#include <memory>
#include <vector>

#include "block.h"

class Grid;

enum class Shape { SQUARE, LEFT_LSHAPE, RIGHT_LSHAPE, LINE, TSHAPE, };

// technically called Tetromino - geometric shape composed of four squares, connected orthogonally
class Shapes {
public:


	Shapes();

	void init_blocks();
	//Shape make_shape(Shape);
	void move_down();
	void move_horizontal(int amount);

	void rotate_shape();
	void set_current_selected_shape(Shape);
	//Shape& get_current_selected_shape();
	std::vector<Block> get_current_shape();

	void get_next_shape();

	bool horizontal_collision();
	bool vertical_collision();

	void render_shape(SDL_Renderer*);


private:
	//std::unique_ptr<Shapes> shape;

	// current selected shape
	Shape current_selected_shape;
	std::vector<Block> current_shape_blocks;

	//std::array<Block, 4> shape;
	std::vector<Block> square;
	std::vector<Block> left_lshape;
	std::vector<Block> right_lshape;
	std::vector<Block> line;
	std::vector<Block> tshape;

	int rotation_num;
};