#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"
#include "player.h"

Player::Player(char* name, char* description, Room* room): Creature(name, description, room)
{
	type = PLAYER;
	hp_base = 4;
	attack = attack_base = 4;
	defense = defense_base = 4;
}

void Player::Look()
{
	Room* r = (Room*)room;
	r->Find();
}
void Player::showInventory()
{
	list <Item*>::iterator it;
	for (it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == ITEM) {
			cout << (*it)->name << ": " << (*it)->description << "\n";
		}
	}
	cout << ">";
}
void Player::takeItem(Item * item)
{
	contains.push_back(item);
	room->contains.remove(item);

	setStatistics();
}
void Player::dropItem(Item * item)
{
	room->contains.push_back(item);
	contains.remove(item);

	setStatistics();

}
void Player::ChangeRoom(Entity * roomdestination)
{
	room = roomdestination;
	Look();
}



