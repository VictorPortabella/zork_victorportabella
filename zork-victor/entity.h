#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	NPC,
	PLAYER
};


class Entity
{
public: 
	Entity(char* name, char* description, Entity* room);
	virtual void Look();
	void Find();
	void showDescription();
	Entity* existItem(string* itemname);
	int getAttack();
	int getArmor();
	

public:
		string name;
		string description;
		list<Entity*> contains;
		Entity* room;
		EntityType type;
};

#endif //__Entity__