#ifndef __World__
#define __World__

#include <string>
#include <list>
#include <time.h>

#define TICK_FREQUENCY 0.5f

using namespace std;

class Entity;
class Player;

class World
{
public: World();
	int ExistAction(string *action);
	void UserAction(string *user_decision);
	int Dice();

public:
	Player *player;
};

#endif //__World__