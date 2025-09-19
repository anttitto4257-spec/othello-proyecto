#include <stdio.h>
#define MAX 30
#define TAM 8

void pedirnombre(char nombre[], int numero) {
	printf ("\nPor favor, ingrese el nombre del jugador %d: \n",numero);
	scanf ("%s", nombre);
}

char elegircolor(char nombre[]) {
	char color;
	printf("\n%s, elija el color de su ficha (N para el color Negro,B para el color blanco): ",nombre);
	scanf(" %c", &color); // solo lee el caracter N O B


	if (color == 'N' || color == 'n') { // lo acepta en caso de minuscula o mayuscula
		return 'N'; //devuelve n si el jugador eligio negro
	} else { // si no devuelve directamente B
		return 'B';
	}
	// cuando pones algo random despues de que te pide el color los elije solo,no se se tendriamos que poner algo disinto como que salte eror o algo asi,no se si nos diran algo de eso //
}

//Función para que en pantalla salga el tablero:

char Tablero[TAM][TAM];

void imprimirTablero(char Tablero[TAM][TAM]){
    printf("\n   ");//aca agregue tres espacios para alinear columna con filas
    for(int j = 0; j < TAM; j++){
        printf("%2d ", j); //Declaraciòn de columna
    }
    printf("\n");

    for(int i = 0; i < TAM; i++){
        printf("%2d", i); //Declaración de fila.
        for(int j = 0; j < TAM; j++){
        //Declaración de fila dentro de columna.
            printf("%2c ", Tablero[i][j]);// aca agregue el %2 y un solo espacio despues del %2c para que quede bien 
        }
        printf("\n");
    }
    printf("\n");
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

		char Tablero[TAM][TAM];
	     //Tablero de la matriz pero que tiene puntitos para marcar los espacios.
        for (int i = 0; i < TAM; i++) {
           for (int j = 0; j < TAM; j++) {
            Tablero[i][j] = '.'; //modificar aca por los puntitos, ver lo del espacio
        }
        }

	    imprimirTablero(Tablero); //Funcion void declarada en el main.

		return 0;
	}

