#ifndef __Player__
#define __Player__

#include "creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(char* name, char* description, Room* room);
	void Look();
	void showInventory();
	void takeItem(Item* room);
	void dropItem(Item* room);
	void ChangeRoom(Entity* room);


};

#endif //__Player__