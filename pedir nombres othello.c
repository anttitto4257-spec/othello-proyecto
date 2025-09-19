#include <stdio.h>
#define MAX 30
#define TAM 8

void pedirnombre(char nombre[], int numero) {
    printf ("\nPor favor, ingrese el nombre del jugador %d: ",numero);
    scanf ("%s", nombre);
}

char elegircolor(char nombre[]) {
    char color;
    int valido = 0;
    do {
        printf("\n%s, Elija el color de su ficha (N para el color Negro, B para el color blanco): ", nombre);
        scanf(" %c", &color); // El espacio antes de %c ignora espacios y saltos previos

        if (color == 'N' || color == 'n' || color == 'B' || color == 'b') { //acepta los caracteres en mayuscula y miniuscula
            valido = 1;
        } else {
            printf("Error: esa opcion no es valida, por favor ingrese N para negro, B para blanco.\n");
        }
    } while (!valido);

    if (color == 'N' || color == 'n') {
        return 'N';
    } else {
        return 'B';
    }
} //ahora con este do y while cuando pones algo random salta el invalido y te pide que elijas de nuevo 
void imprimirTablero(char Tablero[TAM][TAM]) {
    printf("\n  "); //aca agre tres espacios para alinear filas y columnas 
    for(int j = 0; j < TAM; j++) {
        printf("%2d ", j);  //Declaraciòn de columna
    }
    printf("\n");

    for(int i = 0; i < TAM; i++) {
        printf("%2d", i); //Declaración de fila.
        for(int j = 0; j < TAM; j++) {
            printf("%2c ", Tablero[i][j]);//aca faltaba el %2c para que quere alineado
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char jugador1[MAX], jugador2[MAX];
    char color1, color2;
    printf("Bienvenido al Othello!\n");

    pedirnombre(jugador1, 1);
    pedirnombre(jugador2, 2);

    color1 = elegircolor(jugador1); //jugador 1 elige primero
    if (color1 == 'N') {
        color2 = 'B';
    } else {
        color2 = 'N';
    }

    printf("\nColores asignados :\n");
    printf("Jugador 1: %s (%c)\n", jugador1, color1);
    printf("Jugador 2: %s (%c)\n", jugador2, color2);

    char Tablero[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            Tablero[i][j] = '.';
        }
    }

    imprimirTablero(Tablero);

    return 0;
}
