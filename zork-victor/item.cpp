#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"

Item::Item(char* name, char* description, Room * room, ItemType itemtype, int attack, int armor): Entity(name, description, room), itemtype(itemtype), attack(attack) , armor(armor)
{
	type = ITEM;
}

int Item::getAttack()
{
	return attack;
}

int Item::getArmor()
{
	return armor;
}
