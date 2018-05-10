#ifndef __Exit__
#define __Exit__

#include <string>
#include "entity.h"

class Room;
class Item;
class Player;

using namespace std;

class Exit : public Entity
{
public:
	Exit(char* name, char* description, Room* room, Room* destination);
	void setLockByEnemies(bool lock);			//bloquea o desbloquea la Exit devido a la existencia de NPC
	void setLockByKey(bool lock, Item* item);	//bloquea o desbloquea la Exit mediante un objeto (usualmente una llave)
	bool isLock(Player* player);				//comprueba si la Exit esta bloqueada
	
public:
	Room* destination;
	Item* key;
	bool locked_by_enemies;
	bool locked_by_key;
};

#endif //__Item__