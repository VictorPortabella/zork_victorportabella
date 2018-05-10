#ifndef __Room__
#define __Room__

#include <string>
#include <list>
#include "entity.h"

class Exit;
class Item;

using namespace std;

class Room : public Entity
{
public:
	Room(char* name, char* description, Room* room);
	void Find();							//extrae por pantalla la descripcion de la habitacion y su contenido
	Entity* ExistExit(string* exitname);	//comprueba si existe un Exit por su nombre y lo devuelve
	void ListExit();						//extrae por pantalla una lista de los Exit de la Room
	void listItems();						//extrae por pantalla una lista de los Item de la Room
	void listEnemies();						//extrae por pantalla una lista de los NPC de la Room
	Entity* existItem(string* exitname);	//comprueba si existe un Item por su nombre y lo devuelve
	bool allCreaturesDead();				//comprueba si los NPC de la habitacion estan vivos
	Entity* existCreature(string* creaturename);//comprueba si existe un NPC por su nombre y lo devuelve

};


#endif //__Room__