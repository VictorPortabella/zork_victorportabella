#ifndef __Room__
#define __Room__

#include <string>
#include <list>
#include "entity.h"

class Exit;
class Item;

using namespace std;

class Room : public Entity
{
public:
	Room(char* name, char* description, Room* room);
	void Find();
	Entity* ExistExit(string* exitname);
	void ListExit();
	void listItems();
	void listEnemies();
	Entity* existItem(string* exitname);
	bool allCreaturesDead();
	Entity* existCreature(string* creaturename);

};


#endif //__Room__