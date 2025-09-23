#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <stdbool.h> // <-- Ya no hace falta

#define MAX 30
#define TAM 8

void pedirnombre(char nombre[], int numero) {
	printf ("\nIngrese el nombre del jugador %d: ",numero);
	scanf ("%s", nombre);
}

char elegircolor(char nombre[]) {
	char color;
	int valido = 0;
	do {
		printf("\n%s, Elija el color de su ficha (N para el color Negro, B para el color blanco): ", nombre);
		scanf(" %c", &color);
		if (color == 'N' || color == 'n' || color == 'B' || color == 'b') {
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
}

void imprimirTablero(char Tablero[TAM][TAM]) {
	printf("\n  ");
	for(int j = 0; j < TAM; j++) {
		printf("%2d ", j);
	}
	printf("\n");

	for(int i = 0; i < TAM; i++) {
		printf("%2d", i);
		for(int j = 0; j < TAM; j++) {
			printf("%2c ", Tablero[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// FUNCIONES PARA VOLTEAR FICHAS EN CADA DIRECCION

int arriba(char Tablero[TAM][TAM], int f, int c, char color) {
	int fila = f - 1;
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

int abajo(char Tablero[TAM][TAM], int f, int c, char color) {
	int fila = f + 1;
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

int izq(char Tablero[TAM][TAM], int f, int c, char color) {
	int columna = c - 1;
	char rival = (color == 'N') ? 'B' : 'N';
	int capturadas = 0;
	while (columna >= 0 && Tablero[f][columna] == rival) {
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

int der(char Tablero[TAM][TAM], int f, int c, char color) {
	int columna = c + 1;
	char rival = (color == 'N') ? 'B' : 'N';
	int capturadas = 0;
	while (columna < TAM && Tablero[f][columna] == rival) {
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

// Calcula cuC!ntas fichas se voltearC-an si se juega en (f, c)
int puede_capturar(char Tablero[TAM][TAM], int f, int c, char color) {
	if (Tablero[f][c] != '.') return 0;
	char rival = (color == 'N') ? 'B' : 'N';
	int total = 0;
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


// Una jugada es vC!lida si captura al menos una ficha
int jugadavalida(char Tablero[TAM][TAM], int f, int c, char color) {
	return puede_capturar(Tablero, f, c, color) > 0;
}

void jugadajugador(char Tablero[TAM][TAM], char color) {
	int f, c;
	do {
		printf("Ingrese fila y columna: ");
		scanf("%d %d", &f, &c);
		if (!jugadavalida(Tablero, f, c, color)) {
			printf("Jugada invC!lida. Debe capturar al menos una ficha.\n");
		}
	} while(!jugadavalida(Tablero, f, c, color));

	Tablero[f][c] = color;
	arriba(Tablero, f, c, color);
	abajo(Tablero, f, c, color);
	izq(Tablero, f, c, color);
	der(Tablero, f, c, color);
	arribaizq(Tablero, f, c, color);
	arribader(Tablero, f, c, color);
	abajoizq(Tablero, f, c, color);
	abajoder(Tablero, f, c, color);
}

// El sistema juega la jugada mC!s ventajosa (la que voltea mC!s fichas)
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
		printf("El sistema juega en la posiciC3n: %d %d\n", mejorF, mejorC);
		Tablero[mejorF][mejorC] = color;
		arriba(Tablero, mejorF, mejorC, color);
		abajo(Tablero, mejorF, mejorC, color);
		izq(Tablero, mejorF, mejorC, color);
		der(Tablero, mejorF, mejorC, color);
		arribaizq(Tablero, mejorF, mejorC, color);
		arribader(Tablero, mejorF, mejorC, color);
		abajoizq(Tablero, mejorF, mejorC, color);
		abajoder(Tablero, mejorF, mejorC, color);
	} else {
		printf("El sistema no tiene jugadas vC!lidas.\n");
	}
}

char sortearColor() {
	return (rand() % 2 == 0) ? 'N' : 'B';
}

int tiene_jugada_valida(char Tablero[TAM][TAM], char color) { //  agregado
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			if (Tablero[i][j] == '.' && jugadavalida(Tablero, i, j, color)) {
				return 1; // verdadero
			}
		}
	}
	return 0; // falso
}


int main() {
    char jugador1[MAX], jugador2[MAX];
    char color1, color2;
    char colorQueEmpieza;
    char colorSistema = '\0';
    int mododejuego = 1;
    int seguir_jugando = 1;

    printf("Bienvenido al Othello!\n");

    printf("\nSeleccione modo de juego:\n");
    printf("1. Jugar contra otra persona\n");
    printf("2. Jugar contra el sistema\n");
    printf("Ingrese 1 o 2: ");
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
        jugador2[i] = '\0';
    }

    color1 = elegircolor(jugador1);
    color2 = (color1 == 'N') ? 'B' : 'N';

    if (mododejuego == 2) {
        colorSistema = color2;
    }

    printf("\nColores asignados :\n");
    printf("Jugador 1: %s (%c)\n", jugador1, color1);
    printf("Jugador 2: %s (%c)\n", jugador2, color2);

    srand(time(NULL));

    do {
        // --- INICIO DE UNA PARTIDA ---
        char Tablero[TAM][TAM];
        for (int i = 0; i < TAM; i++)
            for (int j = 0; j < TAM; j++)
                Tablero[i][j] = '.';

        Tablero[3][3] = 'B';
        Tablero[3][4] = 'N';
        Tablero[4][3] = 'B';
        Tablero[4][4] = 'N';

        colorQueEmpieza = sortearColor();

        printf("\n¡Sorteo Listo! El color que comienza es: %c\n", colorQueEmpieza);
        if (colorQueEmpieza == color1)
            printf("Empieza %s\n", jugador1);
        else
            printf("Empieza %s\n", jugador2);

        imprimirTablero(Tablero);

        char turno = colorQueEmpieza;
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
                printf("El jugador %c no tiene jugadas válidas y pasa el turno.\n", turno);
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
        printf("Fichas Negras: %d\n", cuentaN);
        printf("Fichas Blancas: %d\n", cuentaB);

        if (cuentaN > cuentaB)
            printf("¡Gana el jugador de color Negro!\n");
        else if (cuentaB > cuentaN)
            printf("¡Gana el jugador de color Blanco!\n");
        else
            printf("¡Empate!\n");
        // --- FIN DE UNA PARTIDA ---

        printf("\n¿Quieres jugar otra vez? (1=Sí, 0=No): ");
        scanf("%d", &seguir_jugando);

    } while (seguir_jugando);

    printf("¡Gracias por jugar Othello!\n");
    printf("Presiona Enter para salir...");
    getchar(); // consume salto de línea pendiente
    getchar(); // espera enter
    return 0;
}
