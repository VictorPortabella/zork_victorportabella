#include <iostream>
#include "exit.h"
#include "item.h"
#include "creature.h"
#include "room.h"
#include <vector>


Room::Room(char* name, char* description, Room* room): Entity(name, description, NULL)
{
	type = ROOM;
}

void Room::Find()
{
	cout << name << ": ";
	cout << description << "\n";

	list <Entity*>::iterator it;

	cout << "Items:\n";
	for (it = contains.begin(); it != contains.end(); ++it){
		if ((*it)->type == ITEM) {
			(*it)->showDescription();
		}
	}

	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == NPC) {
			cout << "Enemigo:\n";
			(*it)->showDescription();
		}
	}
	cout << "Salidas:\n";
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == EXIT) {
			(*it)->showDescription();
		}
	}
	cout << ">";
	

}

Entity* Room::ExistExit(string* exitname)
{
	list <Entity*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->name == *exitname && (*it)->type == EXIT) {
			return *it;
		}
	}
	return NULL;
}

void Room::ListExit()
{
	list <Entity*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == EXIT) {
			cout << (*it)->name << ": " << (*it)->description << "\n";
		}
	}	
	cout << ">";
}

void Room::listItems()
{
	list <Entity*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == ITEM) {
			cout << (*it)->name << ": " << (*it)->description << "\n";
		}
	}
	cout << ">";
}

void Room::listEnemies()
{
	list <Entity*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == NPC) {
			cout << (*it)->name << ": " << (*it)->description << "\n";
		}
	}
	cout << ">";

}

Entity * Room::existItem(string * itemname)
{
	list <Entity*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->name == *itemname && (*it)->type == ITEM) {
			return *it;
		}
	}
	return NULL;
}

bool Room::allCreaturesDead()
{
	list <Entity*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		Creature* cr = (Creature*)*it;
		if ((*it)->type == NPC && cr->isAlive()==true) {
			return false;
		}
	}
	return true;
}

Entity * Room::existCreature(string * creaturename)
{
	list <Entity*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->name == *creaturename && (*it)->type == NPC) {
			return *it;
		}
	}
	return NULL;
}
