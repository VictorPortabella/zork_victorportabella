#ifndef __Item__
#define __Item__

#include <string>
#include "entity.h"

class Room;

using namespace std;

enum ItemType
{
	WEAPON,
	ARMOR,
	USABLE
};

class Item : public Entity
{
public:
	Item(char* name, char* description, Room* room, ItemType itemtype, int attack, int armor);
	int getAttack();
	int getArmor();

public:
	ItemType itemtype;
	int attack;
	int armor;
};

#endif //__Item__