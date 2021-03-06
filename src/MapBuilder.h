#pragma once

#include "GUI/Components/MapComponent.h"
#include "GUI/Components/CharacterComponent.h"

/**
 * Class used to build maps
 */
class MapBuilder
{
public:
	/**
	 * Creates an empty map using width and height
	 */
	static MapBuilder* createEmptyMap(int width, int height);
	/**
	 * Uses an already loaded map
	 */
	static MapBuilder* loadMap(Map* map);
	/**
	 * Load a map from a file in maps/
	 */
	static MapBuilder* loadFromFile(std::string fileName);

	/**
	 * Save map to file  given a file name and a map
	 */
	static MapBuilder* saveToFile(std::string fileName, Map* map);

	/**
	 * spawn the character on the map
	 */
	MapBuilder* spawnCharacter(LivingEntity* character);
	
	/**
	 * Spawn random monsters on the map
	 */
	MapBuilder* spawnRandomMonsters();
	
	/**
	 * Get the built map object
	 */
	Map* get();

	/**
	 * Spawn content relative to character level.
	 * If no character has been spawned, default to lvl 1
	 */
	MapBuilder* spawnScaledContent();

private:
	/**
	 * get the map levels
	 */
	int getMapLevel();
	/**
	 * Constructor private so class is Factory
	 */
	MapBuilder();
	/**
	 * Current map instances
	 */
	Map* map;
	/**
	 * Current character for map
	 */
	LivingEntity* character;
};
