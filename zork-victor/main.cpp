#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "world.h"
#include <stdlib.h>


using namespace std;

#define BACKSPACE "\033[D\033[K"

#define WHITE_ "\033[1;36m"
#define _WHITE "\033[0m"



// Juego conversacional diseñado y desarrollado por: Victor Portabella
int main()
{
	//primera bucle introducido para permitir reiniciar partida
	while (1) {
		World* world = new World();

		std::string action;
		char letra;
		int exist;
		srand(time(NULL));

		action = "ayuda";
		world->ExistAction(&action);
		cout << "\n\n";
		cout << "Estas en el final de tu viaje.\nEres conciente de que la Corona del Rey esta cerca.\nDe todas atrocidades que has tenido que realizar, traicionar a tus amigos es la que mas te reconcome por dentro.\nLlegados a este punto, solo queda seguir hacia delante...\n\n";
		action = "mirar";
		world->ExistAction(&action);
		action = "";

		//segundo bucle introducido para recoger las acciones del usuario recursivamente
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
				else if (letra == '\r') { //intenta realizar la accion mediante el comando "Enter" 
					printf("\n");
					exist = world->ExistAction(&action);
					action.clear();
					if (exist == 0) { //si funcion ExistAction devuelve 0, el input introducido no es correcto
						printf("No puedes hacer eso \n > ");
					}
					else if (exist == -1) { //si funcion ExistAction devuelve -1, se reinicia el juego
						break;
					}
				}
				else { 
					cout << letra;
					action.push_back(letra);
				}
			}
		}
	}
}