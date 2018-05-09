#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"
#include "creature.h"

Creature::Creature(char* name, char* description, Room* room): Entity(name, description, (Entity*)room)
{	
	alive = true;
}

void Creature::Look()
{
	room->Find();
}

void Creature::defineStatistics(int hp_base, int attack_base, int defense_base )
{
	hp = this->hp_base = hp_base;
	attack = this->attack_base=attack_base;
	defense = this->defense_base = defense_base;
}

void Creature::setStatistics()
{
	attack = attack_base;
	defense = defense_base;

	list <Item*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == ITEM && ( (*it)->itemtype == ARMOR || (*it)->itemtype == WEAPON) ) {
			attack = attack + attack_base + (*it)->getAttack();
			defense = defense + defense_base + (*it)->getArmor();
		}
	}
}

Item * Creature::existItem(string * itemname)
{
	list <Item*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->name == *itemname && (*it)->type == ITEM) {
			return *it;
		}
	}
	return NULL;
}

bool Creature::isAlive()
{
	if (hp_base <= 0) {
		alive = false;
	}
	return alive;
}

void Creature::takeItem(Item * room)
{
}

void Creature::dropItem(Item * room)
{
}

void Creature::Attack(Creature* creature, int r)
{
	int damage = attack + r - creature->defense;
	cout << name << " golpea con " << attack + r << " de fuerza\n";
	if (damage > 0) {
		cout << creature->name << " recibe " << damage << " puntos de daño\n";
		creature->hp_base = creature->hp_base - damage;
	}
	else {
		cout << creature->name << " bloquea el golpe\n";
	}
}



