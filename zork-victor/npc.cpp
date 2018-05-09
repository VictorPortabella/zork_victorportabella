#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"
#include "npc.h"

Npc::Npc(char* name, char* description, Room* room) : Creature(name, description, room)
{
	type = NPC;
	hp = hp_base;
	attack = attack_base;
	defense = defense_base;
	setStatistics();
}