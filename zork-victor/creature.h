#ifndef __Creature__
#define __Creature__

#include <string>
#include "entity.h"

class Room;
class Item;

using namespace std;

class Creature : public Entity
{
public: 
	Creature(char* name, char* description, Room* room);
	void Look();						//funcion para obtener descripcion de la habitacion y su contenido
	void defineStatistics(int hp_base, int attack_base, int defense_base);//define las estadisicas de la criatura
	void setStatistics();				//redefine las estadisticas de la criatura dependiendo de su itemizacion
	Item* existItem(string* itemname);	//comprueba mediante el nombre si la criatura tiene un item y lo devuelve
	bool isAlive();						//comprueba si la criatura esta viva
	void takeItem(Item* room);			//recoje un item de la habitacion en la que se encuentra
	void dropItem(Item* room);			//deja un item en la habitacion en la que se encuentra


public:
	list<Item*> contains;
	void Attack(Creature* creature, int r);

	int hp_base;
	int attack_base;
	int defense_base;

	int hp;
	int attack;
	int defense;

	bool alive;
};

#endif //__Creature__