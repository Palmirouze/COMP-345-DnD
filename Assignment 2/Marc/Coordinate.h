//! @file 
//! @brief Header file for the Coordinate class.
//!
#pragma once
#include "stdafx.h"
#include <iostream>
using std::cout;

//! class that represents a Coordinate and its attributes, namely its x and y values and its output format
class Coordinate
{

private:

	int x;
	int y;

	friend std::ostream& operator<<(std::ostream&, const Coordinate&);

public:

	Coordinate();
	Coordinate(int x, int y);
	Coordinate(const Coordinate &coord);

	int getX() { return x; }
	void setX(int i) { x = i; }
	int getY() { return y; }
	void setY(int i) { y = i; }

};