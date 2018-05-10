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
	int ExistAction(string *action);		//ejecuta accion mediante el input del usuario
	void UserAction(string *user_decision);	//recoje input del usuario
	int Dice();								//valor aleatorio entre 1 y 6

public:
	Player *player;
};

#endif //__World__