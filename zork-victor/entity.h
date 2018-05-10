#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	NPC,
	PLAYER
};


class Entity
{
public: 
	Entity(char* name, char* description, Entity* room);
	virtual void Look(); //funcion para obtener descripcion de la habitacion y su contenido
	void Find();		//extrae por pantalla la descripcion de la habitacion y su contenido
	void showDescription(); //extrae por pantalla nombre y descripcion de un objeto Entity
	Entity* existItem(string* itemname); //comprueba mediante el nombre si existe un item y lo devuelve
	int getAttack();	//obtiene el valor de ataque de un item
	int getArmor();		//obtiene el valor de defensa de un item
	

public:
		string name;
		string description;
		list<Entity*> contains;
		Entity* room;
		EntityType type;
};

#endif //__Entity__