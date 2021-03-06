#include "Monster.h"
#include "character.h"
#include "Map.h"

Monster::Monster():LivingEntity('M')
{
	setPathfinderDistance(8);
	setName("Monster");
}
Monster::Monster(char c):LivingEntity(c)
{
	setPathfinderDistance(8);
}



bool Monster::interact(Map* map, Entity* entity)
{
	if(Character* c = dynamic_cast<Character*>(entity))
	{
		if(c->hit(getStrength()*2))
		{
			map->removeEntity(c->getPositionX(), c->getPositionY());
		}
		return true;
	} 
	return false;
}

