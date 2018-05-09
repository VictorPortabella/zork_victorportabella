#include <iostream>
#include <conio.h>
#include <time.h>
#include "entity.h"
#include "creature.h"
#include "item.h"
#include "exit.h"
#include "room.h"
#include "player.h"
#include "world.h"
#include "npc.h"


class Room;

World::World()
{
	Room* room1 = new Room("pasillo","Llegas al final del pasillo. En las entrañas del castillo de DoomSoul , una solida puerta de madera espera tu llegada", NULL);
	Room* room2 = new Room("gran salon", "Te encuentras en un gran salon iluminado por grandes antorchas en las paredes.\nLas sombras bailan a tu alrededor mientras lo cruzas con cautela.", NULL);
	Room* room3 = new Room("altar", "Una pequeña sala con un altar en el fondo. La sala esta repleta de esqueletos con los huesos brutalmente destruidos",NULL);
	Room* room4 = new Room("habitacion secreta", "Al apretar el ladrillo te adentras casi completamente a oscuras en una pequeña habitacion repleta de polvo.\nAl momento te fijas en un solitario cofre al fondo de la camara", NULL);
	Room* room5 = new Room("antecamara del rey", "Sabes que has llegado al final de tu camino. Esta es la ultima oportunidad de salvar los ultimos trozos de tu desdichada alma.\nSin embargo, la llamada de la Corona parece demasiado fuerte para resistirse...", NULL);
	Room* room6 = new Room("arrepentirse", "En un acto de lucidez, decides dar media vuelta. Sin mirar atras, vuelves por donde has venido, dispuesto a redimirte de tus pecados", NULL);
	Room* room7 = new Room("salon reial", "El trono se alza ante ti. Unas pequeñas escaleras te dirigen hacia tu destino.", NULL);


	Exit* exit12 = new Exit("puerta de madera", "Una gran puerta de madera construida hace eras. No parece bloqueada", room1, room2);
	exit12->setLockByEnemies(false);
	exit12->setLockByKey(false, NULL);
	room1->contains.push_back(exit12);

	Exit* exit23 = new Exit("puerta este", "En el lado este de la sala encuentras una pequeña puerta de madera destartalada", room2, room3);
	exit23->setLockByEnemies(false);
	exit23->setLockByKey(false, NULL);
	room2->contains.push_back(exit23);

	Exit* exit32 = new Exit("puerta este", "Vuelve al gran salon", room3, room2);
	exit32->setLockByEnemies(false);
	exit32->setLockByKey(false, NULL);
	room3->contains.push_back(exit32);

	Exit* exit24 = new Exit("puerta oculta", "En el lado oeste de la sala ves un ladrillo suelto en la pared.", room2, room4);
	exit24->setLockByEnemies(false);
	exit24->setLockByKey(false, NULL);
	room2->contains.push_back(exit24);

	Exit* exit42 = new Exit("puerta oculta", "Vuelve al gran salon.", room4, room2);
	exit42->setLockByEnemies(false);
	exit42->setLockByKey(false, NULL);
	room4->contains.push_back(exit42);

	Item* llave = new Item("llave", "Una gran llave dorada se encuentra encima del altar", room3, USABLE, NULL, NULL);
	room3->contains.push_back(llave);

	Exit* exit25 = new Exit("puerta majestuosa", "Una puerta tallada meticulosamente se encuentra al final de la sala. Una gran cerradura asegura que solo los dignos puedan pasar", room2, room5);
	exit25->setLockByEnemies(false);
	exit25->setLockByKey(true, llave);
	room2->contains.push_back(exit25);

	Exit* exit56 = new Exit("arrepentirse", "Arrepentirse", room5, room6);
	exit56->setLockByEnemies(false);
	exit56->setLockByKey(false, NULL);
	room5->contains.push_back(exit56);

	Exit* exit57 = new Exit("corona", "Adentrarse en el Salon Reial", room5, room7);
	exit57->setLockByEnemies(false);
	exit57->setLockByKey(false, NULL);
	room5->contains.push_back(exit57);


	Item* espada = new Item("claymore", "Un mandoble de hierro reforjado descansa en el cofre", room4, WEAPON, 6, NULL);
	room4->contains.push_back(espada);

	Item* armadura = new Item("armadura", "Un armadura completa descansa en el cofre  ", room4, ARMOR, NULL, 6);
	room4->contains.push_back(armadura);


	player = new Player("heroe", "", room1);

	Npc* npc = new Npc("armadura animada", "Una armadura descansa frente al altar. Nada mas entrar en la habitacion, se pone en guardia frente a ti", room3);
	npc->defineStatistics(10,10,10);
	room3->contains.push_back(npc);

	Npc* rey = new Npc("rey", "Imponente, el rey se alza ante ti. No dudara en acabar con tu vida si se lo permites", room7);
	rey->defineStatistics(10, 8, 12);
	room7->contains.push_back(rey);

	Item* corona = new Item("corona", "La corona. El anhelo de toda una vida...", room7, USABLE, NULL, NULL);
	room7->contains.push_back(corona);
}

int World::ExistAction(string *action)
{
	string user_decision="";
	string* ptud = &user_decision;
	Room* r;
	r = (Room*)player->room;
	int d;


	if (*action == "atacar") {
		cout << "¿A quien quieres atacar?\n>";
		r->listEnemies();
		UserAction(ptud);
		Creature* cr = (Creature*)r->existCreature(ptud);
		if (cr != NULL) {
			while (*ptud != ("")) {
				cout << "Presiona Enter para golpear\n>";
				UserAction(ptud);
				d = Dice();
			}
			player->Attack(cr, d);
			if (cr->isAlive() == true) {
				d = Dice();
				cr->Attack(player, d);
			}
			else {
				cout << cr->name << " ha muerto\n";
				r->contains.remove(cr);
			}
			if (player->isAlive() == false) {
				cout << "HAS MUERTO\n" << "Presiona enter para reiniciar\n>";
				UserAction(ptud);
				while (*ptud != ("")) {

				}
				return -1;
			}
			cout << ">";
		}
		else {
			cout << "No puedes atacar a eso \n>";
		}
		return 1;
	}
	else if (*action == "ayuda") {
		cout << "Acciones:\natacar\nayuda\ncoger\ndejar\ninventario\nir\nmirar\n> ";

	}
		  else if (*action=="coger") {
			if (r->allCreaturesDead() == true) {
				cout << "¿Que quieres coger?" << "\n";
				r->listItems();
				UserAction(ptud);
				Item* i = (Item*)r->existItem(ptud);
				if (i != NULL) {
					player->takeItem(i);
					cout << i->name << " cogido con exito \n>";
					if (i->name == "corona") {
						cout << "¡Eres el nuevo rey!\nUn nuevo futuro te aguarda\n" << "Presiona enter para reiniciar\n>";
						UserAction(ptud);
						while (*ptud != ("")) {
						}
						return -1;	
					}
				}
				else {
					cout << "No puedes coger eso \n>";
				}
			}
			else {
				cout << "Una criatura te impide coger eso \n>";
			}
			return 1;
			}
		else if (*action=="mirar") {
			player->Look();
			return 1;
		}
		else if (*action=="ir") {
			cout << "¿Por donde quieres ir?" << "\n";
			r->ListExit();
			UserAction(ptud);
			Exit* ex = (Exit*)r->ExistExit(ptud);
			if (ex != NULL) {
				if (ex->isLock(player) == false) {
					Entity* des = &(*ex->destination);
					if (des->name == "arrepentirse") {
						cout << "¡Has salvado tu alma!\nUn nuevo futuro te aguarda\n" << "Presiona enter para reiniciar\n>";
						UserAction(ptud);
						while (*ptud != ("")) {
						}
						return -1;
					}
					player->ChangeRoom(des);
				}
			}
			else {
				cout << "No puedes ir por ahi \n>";
			}
			return 1;
		}
		else if (*action == "inventario") {
			player->showInventory();
			return 1;
		}
		else if (*action == "dejar") {
			cout << "¿Que quieres dejar?" << "\n";
			player->showInventory();
			UserAction(ptud);
			Item* i = (Item*)player->existItem(ptud);
			if (i != NULL) {
				player->dropItem(i);
				cout << i->name << " dejado con exito \n>";
			}
			else {
				cout << "No tienes eso \n>";
			}
			return 1;
		}
		else {
			return 0;
		}

		
}

void World::UserAction(string *user_decision)
{
	std::string action;
	char letra;
	bool exist;

	while (true) {

		if (kbhit != 0) {

			letra = getch();

			if (letra == '\b') {
				if (action.size() > 0) {
					action.pop_back();
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
			}
			else if (letra == '\r') { //Ejecutamos accion
				printf("\n");
				*user_decision = action;
				break;
			}
			else {
				cout << letra;
				action.push_back(letra);
			}
		}
	}
}

int World::Dice()
{	
	int d = (rand()%6) + 1;
	return  d;
}

