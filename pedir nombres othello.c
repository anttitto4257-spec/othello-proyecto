#include <stdio.h>
#define MAX 30

void pedirnombre(char nombre[], int numero) {
	printf ("Ingrese el nombre del jugador %d: ",numero);
	scanf ("%s", nombre);
}

char elegircolor(char nombre[]) {
	char color;
	printf("%s, elija el color de su ficha (N para el color Negro,B para el color blanco): ",nombre);
	scanf(" %c", &color); // solo lee el caracter N O B


	if (color == 'N' || color == 'n') { // lo acepta en caso de minuscula o mayuscula
		return 'N'; //devuelve n si el jugador eligio negro
	} else { // si no devuelve directamente B
		return 'B';
	} 
	// cuando pones algo random despues de que te pide el color los elije solo,no se se tendriamos que poner algo disinto como que salte eror o algo asi,no se si nos diran algo de eso //
}
	int main() {
		char jugador1[MAX], jugador2[MAX]; //arrays nombres
		char color1, color2;
		printf("Bienvenido al Othello!\n");

		pedirnombre(jugador1, 1);
		pedirnombre(jugador2, 2);

		color1 = elegircolor(jugador1);//jugador 1 elige primero
		if (color1 == 'N') {
			color2 = 'B';
		} else {
			color2 = 'N';
		}

		printf("\nColores asignados :\n");
		printf("Jugador 1: %s (%c)\n", jugador1, color1);
		printf("Jugador 2: %s (%c)\n", jugador2, color2);

		return 0;
	}