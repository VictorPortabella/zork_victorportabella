#include <iostream>
#include "Entity.h"

Entity::Entity(char* name, char* description, Entity* room):name(name), description(description), room(room)
{
	type = ENTITY;
}

void Entity::Look()
{
}
void Entity::Find()
{
	cout << name;
}

void Entity::showDescription()
{
	cout << description << "\n";
}

Entity * Entity::existItem(string * itemname)
{
	list <Entity*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		cout << (*it)->name;
		if ((*it)->name == *itemname && (*it)->type == ITEM) {
			return *it;
		}
	}
	return NULL;
}

int Entity::getAttack()
{
	return NULL;
}

int Entity::getArmor()
{
	return NULL;
}

