#pragma once
#include "Tile.h"
#include "Entity.h"
#include "Subject.h"

class Map : public Subject
{

private:

	Tile ***tileGrid;
	Coordinate* playerCoordinate;
	Coordinate* exitCoordinate;

	int width;
	int height;

	Coordinate* spawnPlayer();
	Tile* setDestinationTile(char input);

	bool interactWith(Tile* tile);
	void attackMonster(Tile* tile);
	void openChest(Tile* tile);
	void endMap();

public:

	Map();
	Map(int width, int height);
	~Map();

	void generateMap();

	Tile* getTile(int x, int y);

	int getWidth() { return width; }
	int getHeight() { return height; } 

	bool isCompleted();
	bool controlPlayer(char input);
	void movePlayer(Tile* tile);
	
	Coordinate* getPlayerCoordinate() { return playerCoordinate; }

};