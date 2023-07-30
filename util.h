#pragma once


struct BlockCoords {
	
	int x;
	int y;

	BlockCoords() :
		x(0), y(0)
	{
	}
	BlockCoords(int x, int y)
		: x(x), y(y)
	{
	}

};