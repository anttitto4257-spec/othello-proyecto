
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 30
#define TAM 8 //Declaración de macro para el tamaño de la matriz 8x8.

//Función para pedir el nombre al o a los jugadores.
void pedirnombre(char nombre[], int numero) {
	printf ("\nPor favor, ingrese el nombre del jugador %d: ",numero);
	scanf ("%s", nombre);
}

//Función para elegir el color.
char elegircolor(char nombre[]) {
	char color;
	int valido = 0;

	do {
		printf("\n%s, Elija el color de su ficha (N para el color Negro, B para el color blanco): ", nombre);
		scanf(" %c", &color); // El espacio antes de %c ignora espacios y saltos previos

		if (color == 'N' || color == 'n' || color == 'B' || color == 'b') { //Acepta los caracteres en mayúscula y minúscula.
			valido = 1;
		} else {
			printf("Error: esa opcion no es valida, por favor ingrese N para negro, B para blanco.\n"); //Error si elige otra opción.
		}

	} while (!valido);

	if (color == 'N' || color == 'n') {
		return 'N';
	} else {
		return 'B';
	}
}
//Gracias al do - while al escribir algo incorrecto te pide que elijas nuevamente.



//Función para imprimir el tablero en pantalla.
void imprimirTablero(char Tablero[TAM][TAM]) {
	printf("\n  "); //Agregamos espacios para alinear las filas con las columnas.
	for(int j = 0; j < TAM; j++) {
		printf("%2d ", j);  //Declaración de columnas.
	}
	printf("\n");

	for(int i = 0; i < TAM; i++) {
		printf("%2d", i); //Declaración de filas.
		for(int j = 0; j < TAM; j++) {
			printf("%2c ", Tablero[i][j]);//Declaración de columnas dentro de las filas.
		}
		printf("\n");
	}
	printf("\n");
}


//FUNCIONES PARA MOVER LAS FICHAS EN TODAS LAS DIRECCIONES POSIBLES:

// Voltear las fichas hacia arriba
int arriba(char Tablero[TAM][TAM], int f, int c, char color) {
    int fila = f - 1; //Al restar uno se acerca al 0. Declaramos una nueva variable fila para no modificar la original.
    char rival = (color == 'N') ? 'B' : 'N';
    int capturadas = 0;
    while (fila >= 0 && Tablero[fila][c] == rival) {
        capturadas++;
        fila--;
    }
    if (fila >= 0 && Tablero[fila][c] == color && capturadas > 0) {
        for (int i = 1; i <= capturadas; i++)
            Tablero[f - i][c] = color;
            return capturadas;
    }
    return 0;
}


// Voltear las fichas hacia abajo
int abajo(char Tablero[TAM][TAM], int f, int c, char color) {
    int fila = f + 1; //Al suma uno se acerca al tamaño máximo de la matriz. Declaramos una nueva variable fila para no modificar la original.
    char rival = (color == 'N') ? 'B' : 'N';
    int capturadas = 0;
    while (fila < TAM && Tablero[fila][c] == rival) {
        capturadas++;
        fila++;
    }
    if (fila < TAM && Tablero[fila][c] == color && capturadas > 0) {
        for (int i = 1; i <= capturadas; i++)
            Tablero[f + i][c] = color;
            return capturadas;
    }
    return 0;
}


//Voltear las fichas hacia la izq
int izq(char Tablero[TAM][TAM], int f, int c, char color) {
     int columna = c - 1; //Al restar uno se acerca al 0. Declaramos una nueva variable columna para no modificar la original.
     char rival = (color == 'N') ? 'B' : 'N';
     int capturadas = 0;
     while (columna >= 0 && Tablero[f][columna] == rival){
        capturadas++;
        columna--;
     }
    if (columna >= 0 && Tablero[f][columna] == color && capturadas > 0) {
        for (int i = 1; i <= capturadas; i++)
            Tablero[f][c - i] = color;
            return capturadas;
    }
    return 0;
}


//Voltear las fichas hacia la der
int der(char Tablero[TAM][TAM], int f, int c, char color) {
     int columna = c + 1; //Al sumar uno se acerca al tamaño máximo de la matriz. Declaramos una nueva variable columna para no modificar la original.
     char rival = (color == 'N') ? 'B' : 'N';
     int capturadas = 0;
     while (columna < TAM && Tablero[f][columna] == rival){
        capturadas++;
        columna++;
     }
     if (columna < TAM && Tablero[f][columna] == color && capturadas > 0) {
        for (int i = 1; i <= capturadas; i++)
        Tablero[f][c + i] = color;
     return capturadas;
    }
    return 0;
}

//Continuamos con la misma modalidad pero modificando suma y resta de filas y columnas según que movimiento corresponda:

//Voltear fichas en diagonal arriba para la izq
int arribaizq(char Tablero[TAM][TAM], int f, int c, char color) {
    int fila = f - 1, columna = c - 1;
    char rival = (color == 'N') ? 'B' : 'N';
    int capturadas = 0;
    while (fila >= 0 && columna >= 0 && Tablero[fila][columna] == rival) {
        capturadas++;
        fila--, columna--;
    }
    if (fila >= 0 && columna >=0 && Tablero[fila][columna] == color && capturadas > 0) {
        for (int i = 1; i <= capturadas; i++)
            Tablero[f - i][c - i] = color;
    return capturadas;
    }
    return 0;
}


//Voltear fichas en diagonal arriba para la der
int arribader(char Tablero[TAM][TAM], int f, int c, char color) {
    int fila = f - 1, columna = c + 1;
    char rival = (color == 'N') ? 'B' : 'N';
    int capturadas = 0;
    while (fila >= 0 && columna < TAM && Tablero[fila][columna] == rival) {
        capturadas++;
        fila--, columna++;
    }
    if (fila >= 0 && columna < TAM && Tablero[fila][columna] == color && capturadas > 0) {
        for (int i = 1; i <= capturadas; i++)
            Tablero[f - i][c + i] = color;
    return capturadas;
    }
    return 0;
}


//Voltear fichas en diagonal abajo para la izq
int abajoizq(char Tablero[TAM][TAM], int f, int c, char color) {
    int fila = f + 1, columna = c - 1;
    char rival = (color == 'N') ? 'B' : 'N';
    int capturadas = 0;
    while (fila < TAM && columna >= 0 && Tablero[fila][columna] == rival) {
        capturadas++;
        fila++, columna--;
    }
    if (fila < TAM && columna >=0 && Tablero[fila][columna] == color && capturadas > 0) {
        for (int i = 1; i <= capturadas; i++)
            Tablero[f + i][c - i] = color;
    return capturadas;
    }
    return 0;
}

//Voltear fichas en diagonal abajo para la der
int abajoder(char Tablero[TAM][TAM], int f, int c, char color) {
    int fila = f + 1, columna = c + 1;
    char rival = (color == 'N') ? 'B' : 'N';
    int capturadas = 0;
    while (fila < TAM && columna < TAM && Tablero[fila][columna] == rival) {
        capturadas++;
        fila++, columna++;
    }
    if (fila < TAM && columna < TAM && Tablero[fila][columna] == color && capturadas > 0) {
        for (int i = 1; i <= capturadas; i++)
            Tablero[f + i][c + i] = color;
    return capturadas;
    }
    return 0;
}



//Para capturar fichas.
int puede_capturar(char Tablero[TAM][TAM], int f, int c, char color) {
    if (Tablero[f][c] != '.') return 0;

    char rival = (color == 'N') ? 'B' : 'N';
    int total = 0;

    // Para cada dirección [df (dirección-fila), dc (dirección-columna)]

    int dirs[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    for (int d = 0; d < 8; d++) {
        int df = dirs[d][0], dc = dirs[d][1];
        int ff = f + df, cc = c + dc;
        int count = 0;
        while (ff >= 0 && ff < TAM && cc >= 0 && cc < TAM && Tablero[ff][cc] == rival) {
            count++;
            ff += df;
            cc += dc;
        }
        if (count > 0 && ff >= 0 && ff < TAM && cc >= 0 && cc < TAM && Tablero[ff][cc] == color)
            total += count;
    }
    return total;
}


// Una jugada es válida si captura al menos una ficha
bool jugadavalida(char Tablero[TAM][TAM], int f, int c, char color) {
    return puede_capturar(Tablero, f, c, color) > 0;
}

int contar_fichas_capturadas(char Tablero[TAM][TAM], int f, int c, char color) {
    int total = 0;
    total += arriba(Tablero, f, c, color);
    total += abajo(Tablero, f, c, color);
    total += izq(Tablero, f, c, color);
    total += der(Tablero, f, c, color);
    total += arribaizq(Tablero, f, c, color);
    total += arribader(Tablero, f, c, color);
    total += abajoizq(Tablero, f, c, color);
    total += abajoder(Tablero, f, c, color);
    return total;
}


//Función para que juegue el jugador.
void jugadajugador(char Tablero[TAM][TAM], char color) {
    int f, c, capturadas = 0;

    do{
        printf("Ingrese fila y columna: ");
        scanf("%d %d", &f, &c);
        if (!jugadavalida(Tablero, f, c, color)){
            printf("Jugada invalida, debes capturar por lo menos una ficha para continuar.\n");
        }
    }while(!jugadavalida(Tablero, f, c, color));

    Tablero[f][c] = color;

    // --- Aquí llamamos a contar_fichas_capturadas para ver cuántas fichas se capturaron ---
    capturadas += arriba(Tablero, f, c, color);
    capturadas += abajo(Tablero, f, c, color);
    capturadas += izq(Tablero, f, c, color);
    capturadas += der(Tablero, f, c, color);
    capturadas += arribaizq(Tablero, f, c, color);
    capturadas += arribader(Tablero, f, c, color);
    capturadas += abajoizq(Tablero, f, c, color);
    capturadas += abajoder(Tablero, f, c, color);

    if(capturadas > 0){
        printf("¡Capturaste %d fichas en esta jugada!\n", capturadas);
    } else {
        printf("La próxima será maestro, no capturaste ninguna ficha en esta jugada.\n");
    }
}

// Función para que el sistema juegue de mejor manera, no juega al azar.
// --- Cambios en jugadasistema ---
// Igual que arriba, solo mostrá el mensaje después de la jugada.
// Lo hacemos solo si el sistema puede jugar (maxCaptura > 0).
void jugadasistema(char Tablero[TAM][TAM], char color) {
    int mejorF = -1, mejorC = -1, maxCaptura = 0;
    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            int captura = puede_capturar(Tablero, f, c, color);
            if (Tablero[f][c] == '.' && captura > maxCaptura) {
                maxCaptura = captura;
                mejorF = f;
                mejorC = c;
            }
        }
    }
    if (maxCaptura > 0) {
        printf("El sistema juega en la posicion: %d %d\n", mejorF, mejorC);
        Tablero[mejorF][mejorC] = color;

        int capturadas = 0;
        capturadas += arriba(Tablero, mejorF, mejorC, color);
        capturadas += abajo(Tablero, mejorF, mejorC, color);
        capturadas += izq(Tablero, mejorF, mejorC, color);
        capturadas += der(Tablero, mejorF, mejorC, color);
        capturadas += arribaizq(Tablero, mejorF, mejorC, color);
        capturadas += arribader(Tablero, mejorF, mejorC, color);
        capturadas += abajoizq(Tablero, mejorF, mejorC, color);
        capturadas += abajoder(Tablero, mejorF, mejorC, color);

        if(capturadas > 0){
            printf("El sistema capturó %d fichas en esta jugada.\n", capturadas);
        } else {
            printf("El sistema no capturó ninguna ficha en esta jugada.\n");
        }
    } else {
        printf("El sistema no tiene jugadas validas.\n");
    }
}

//Función para sortear el color que comienza en la partida.
char sortearColor() {
    return (rand() % 2 == 0) ? 'N' : 'B';
}

//Función para declarar si una jugada es válida.
int tiene_jugada_valida(char Tablero[TAM][TAM], char color) {
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			if (Tablero[i][j] == '.' && jugadavalida(Tablero, i, j, color)) {
				return 1; // Verdadero
			}
		}
	}
	return 0; // Falso
}


int main() {

	char jugador1[MAX], jugador2[MAX];
	char color1, color2;
	char colorQueEmpieza;
    char colorSistema = '\0';

    int mododejuego = 1; // 1 = Contra persona, 2 = Contra sistema
    int seguir_jugando = 1;

	printf("Bienvenido al Othello!\n");

	printf("\nSeleccione modo de juego:\n");
	printf("\n1. Jugar contra otra persona\n");
	printf("\n2. Jugar contra el sistema\n");
	printf("\nIngrese 1 o 2: ");
	scanf("%d", &mododejuego);

	pedirnombre(jugador1, 1);

    if (mododejuego == 1) {
        pedirnombre(jugador2, 2);
    } else {
        char sistema[] = "Sistema";
        int i = 0;
        while (sistema[i] != '\0') {
        jugador2[i] = sistema[i];
        i++;
    }
      jugador2[i] = '\0'; // Fin de cadena
    }



    // Primero se elige el color de cada jugador
    color1 = elegircolor(jugador1);
    color2 = (color1 == 'N') ? 'B' : 'N';

    if (mododejuego == 2) {
        // El sistema siempre es jugador 2 en este código
        colorSistema = color2;
    }

	printf("\nColores asignados :\n");
	printf("Jugador 1: %s (%c)\n", jugador1, color1);
	printf("Jugador 2: %s (%c)\n", jugador2, color2);

	 srand(time(NULL));

    do {
        //INICIO DE LA PARTIDA
        char Tablero[TAM][TAM];
        for (int i = 0; i < TAM; i++)
            for (int j = 0; j < TAM; j++)
                Tablero[i][j] = '.';

        Tablero[3][3] = 'B'; //Posiciones iniciales de las fichas.
        Tablero[3][4] = 'N';
        Tablero[4][3] = 'B';
        Tablero[4][4] = 'N';

        colorQueEmpieza = sortearColor();


    printf("\n¡Sorteo Listo!\nEl color que comienza es: %c\n", colorQueEmpieza);

    // Se determina qué jugador tiene ese color y cuál comienza.
    if (colorQueEmpieza == color1) {
        printf("Empieza %s\n", jugador1);
    } else {
        printf("Empieza %s\n", jugador2);
    }

	imprimirTablero(Tablero);

    char turno = colorQueEmpieza;  //Turnos.
    int sin_jugadas_consecutivas = 0;
        while (1) {
            printf("\nTurno de color %c\n", turno);

            if (tiene_jugada_valida(Tablero, turno)) {
                sin_jugadas_consecutivas = 0;
                if (mododejuego == 2 && turno == colorSistema) {
                    jugadasistema(Tablero, turno);
                } else {
                    jugadajugador(Tablero, turno);
                }
                imprimirTablero(Tablero);
            } else {
                printf("El jugador %c no tiene jugadas validas y pasa el turno.\n", turno);
                sin_jugadas_consecutivas++;
            }

            turno = (turno == 'N') ? 'B' : 'N';

            if (sin_jugadas_consecutivas == 2) {
                break;
            }
            int lleno = 1;
            for (int i = 0; i < TAM; i++)
                for (int j = 0; j < TAM; j++)
                    if (Tablero[i][j] == '.') lleno = 0;
            if (lleno) {
                break;
            }
        }

    int cuentaN = 0, cuentaB = 0;
       for (int i = 0; i < TAM; i++)
            for (int j = 0; j < TAM; j++) {
                if (Tablero[i][j] == 'N') cuentaN++;
                if (Tablero[i][j] == 'B') cuentaB++;
            }

        printf("¡Fin del juego!\n");
        printf("Fichas Negras: %d\n", cuentaN); //Cuenta la cantidad de fichas de cada jugador.
        printf("Fichas Blancas: %d\n", cuentaB);

        if (cuentaN > cuentaB)
            printf("¡Gana el jugador de color Negro!\n"); //Determina el ganador.
        else if (cuentaB > cuentaN)
            printf("¡Gana el jugador de color Blanco!\n");
        else
            printf("¡Empate!\n");
        //FIN DE LA PARTIDA

        printf("\n¿Quieres jugar otra vez? (1=Si, 0=No): ");
        scanf("%d", &seguir_jugando);

    } while (seguir_jugando);

    printf("¡Gracias por jugar Othello!\n");
    printf("Presiona Enter para salir...");
    getchar(); // consume salto de línea pendiente
    getchar(); // espera enter
    return 0;

}
