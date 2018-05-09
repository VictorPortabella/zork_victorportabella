#ifndef __Creature__
#define __Creature__

#include <string>
#include "entity.h"

class Room;
class Item;

using namespace std;

class Creature : public Entity
{
public: 
	Creature(char* name, char* description, Room* room);
	void Look();
	void defineStatistics(int hp_base, int attack_base, int defense_base);
	void setStatistics();
	Item* existItem(string* itemname);
	bool isAlive();
	void takeItem(Item* room);
	void dropItem(Item* room);


public:
	list<Item*> contains;
	void Attack(Creature* creature, int r);

	int hp_base;
	int attack_base;
	int defense_base;

	int hp;
	int attack;
	int defense;

	bool alive;
};

#endif //__Creature__