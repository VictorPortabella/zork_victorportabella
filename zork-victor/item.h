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
	int getAttack();	//obtiene el valor de ataque de un item
	int getArmor();		//obtiene el valor de defensa de un item

public:
	ItemType itemtype;
	int attack;
	int armor;
};

#endif //__Item__