#include <iostream>
#include "room.h"
#include "item.h"
#include "Exit.h"
#include "Player.h"



Exit::Exit(char* source, char* description, Room* room, Room* destination):Entity(source, description, (Entity*) room), destination(destination)
{
	type = EXIT;
	locked_by_enemies = false;
	locked_by_key = false;
}
void Exit::setLockByEnemies(bool lock)
{
	locked_by_enemies = lock;
}

void Exit::setLockByKey(bool lock, Item * item)
{
	locked_by_key = lock;
	key = item;
}

bool Exit::isLock(Player* player)
{
	bool aux = false;
	bool aux1 = false;
	string k = "";
	string* ptk = &k;
	

	if (locked_by_enemies == true) {
		aux = true;
		Room* r = (Room*)room;
		if (r->allCreaturesDead() == true) {
			setLockByEnemies(false);
			aux = false;
		}
		else {
			cout << "Una criatura te impide el paso \n";
		}
	}
	if (locked_by_key == true) {
		aux1 = true;
		k = key->name;
		if ((player->existItem(ptk)) != NULL) {
			setLockByKey(false, NULL);
			aux1 = false;
			cout << "Has abierto la puerta con  " << k << "\n";
		}
		else {
			cout << "La puerta esta bloqueada \n";
		}
	}
	cout << ">";
	if (aux == true || aux1 == true) {
		return true;
	}
	else{
		return false;
	}
}
