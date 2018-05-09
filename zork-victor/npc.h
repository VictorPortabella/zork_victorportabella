#ifndef __Npc__
#define __Npc__

#include "creature.h"

using namespace std;

class Npc : public Creature
{
public:
	Npc(char* name, char* description, Room* room);
};

#endif //__Npc__