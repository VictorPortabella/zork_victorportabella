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
	void setLockByEnemies(bool lock);
	void setLockByKey(bool lock, Item* item);
	bool isLock(Player* player);

public:
	Room* destination;
	Item* key;
	bool locked_by_enemies;
	bool locked_by_key;
};

#endif //__Item__