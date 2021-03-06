#pragma once

#include "map_tile.h"
#include "Entity.h"
#include <vector>
#define TILE_EMPTY 0
#define TILE_WALL 1
#define SPAWNTILE 2
#define ENDTILE 3
#include "Pathfinder.h"
#include "character.h"

class PathFinder;
class Entity;
class Character;
/**
 * A map is a collection of tiles and entities placed in a grid pattern
 */
class Map 
{
private:

	std::string name;

	MapTile ***tileGrid;
	Entity ***entityGrid;

	std::vector<Entity*> entities;

	Character* character;



	int spawnX = 0, spawnY = 0;

	int width;
	int height;

	friend std::ostream& operator<<(std::ostream&, const Map&);

public:
	/**
	 * Create a map with a name, width and height
	 */
	Map(std::string name, int width, int height);
	/**
	 * Create a map with a width, height
	 */
	Map(int width, int height);
	/**
	 * Copy a map
	 */
	Map(const Map &map);

	/**
	 * Get map name
	 */
	std::string getName() { return name; }

	void Map::generateMap(int width, int height);

	/**
	 * Get map tile at x,y
	 */
	MapTile* getTile(int x, int y);
	/**
	 * Set map tile at x,y
	 */
	void setTile(MapTile* tile, int x, int y);

	/**
	 * Get entity at x,y. returns a null pointer if no entity is there
	 */
	Entity* getEntity(int x, int y);

	/**
	 * Move entity at x1,y1 to x2,y2. returns entity if successfull and null pointer if not 
	 */
	Entity* moveEntity(int x1, int y1, int x2, int y2);
	/**
	 * Calls moveEntity(int,int,int,int) using the entities position
	 */
	Entity* moveEntity(Entity* entity, int x, int y);
	/**
	 * remove entity from the map and return the entity instance.
	 */
	Entity* removeEntity(int x, int y);

	/**
	 * Add entity to map at x,y. Returns if spawn was succesfull or not
	 */
	bool spawnEntity(Entity* entity, int x, int y);
	/**
	 * Spawns the character player. Returns if successfull or not
	 */
	bool spawnCharacter(Character* character);

	/**
	 * Get the character. Returns null if not spawned yet
	 */
	Character* getCharacter();
	/**
	 * returns map width
	 */
	int getWidth();
	/**
	 * returns map height
	 */
	int getHeight();
	/**
	 * Simlutate a tick on the map
	 */
	void simulateMapTick();

	/**
	 * Get entities on map
	 */
	std::vector<Entity*>* getEntities();
};