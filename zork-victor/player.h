#ifndef __Player__
#define __Player__

#include "creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(char* name, char* description, Room* room);
	void Look();					//funcion para obtener descripcion de la habitacion y su contenido
	void showInventory();			//extrae por pantalla los objetos en el inventario del jugador
	void takeItem(Item* room);		//recoje un item de la habitacion en la que se encuentra
	void dropItem(Item* room);		//deja un item en la habitacion en la que se encuentra
	void ChangeRoom(Entity* room);	//permite al jugador cambiar de Room mediante la Exit seleccionada


};

#endif //__Player__