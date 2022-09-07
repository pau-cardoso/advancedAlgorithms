/**
 * @file main.cpp
 * @author Paulina Cardoso Fuentes - A01701490
 * @brief Calcula las posiciones donde es posible colocar una reina y que ninguna se coma entre si
 * @date 2021-11-28
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Imprime el tablero con las reinas
 * Complejidad: O(n²)
 * 
 * @param n tamaño del tablero y numero de reinas
 * @param queens vector que indica la posicion de las reinas en el tablero
 */
void printBoard(int n, vector<int> &queens) {
	vector<vector<bool>> board(n, vector<bool> (n, false)); // Tablero de ajedrez
	
	for (int i = 0; i < n; i++) {
		board[queens[i]][i] = true;
	}

	for(int i = 0; i < n; i++){
		cout << "{ ";
		for(int j = 0; j < n; j++){
			if (j == n-1)
				cout << board[i][j] << " ";
			else
				cout << board[i][j] << ", ";
		}
		cout << "}" << endl;
	}
}

/**
 * @brief Calcular los ataques de las reinas a cierta posición
 * Complejidad: O(n)
 * 
 * @param row fila de la posición a analizar
 * @param col columna de la posición a analizar
 * @param queens vector que indica la posicion de las reinas en el tablero
 * @return int número de ataques de las reinas con la posicion dada
 */
int heuristicValue(int row, int col, vector<int> &queens) {
	int attacks = 0;
	for (int i = 0; i < queens.size(); i++) {

		int targetCol = i, targetRow = queens[i];
		if (row == targetRow && col == targetCol)
			continue;

		if (row == targetRow)
			attacks++;
		if (col-row == targetCol-targetRow)
			attacks++;
		if (col+row == targetCol+targetRow)
			attacks++;
	}

	return attacks;
}

/**
 * @brief numero de ataques totales entre las reinas en todo el tablero
 * Coomplejidad: O(n²)
 * 
 * @param queens vector que indica la posicion de las reinas en el tablero
 * @return int número de ataques de las reinas con la posicion dada
 */
int totalAttacks(vector<int> &queens) {
	int attacks = 0;
	for (int i = 0; i < queens.size(); i++) {
		attacks += heuristicValue(queens[i], i, queens);
	}
	
	return attacks;
}

/**
 * @brief Posiciona las reinas en el tablero de manera aleatoria
 * Complejidad: O(n)
 * 
 * @param n tamaño del tablero y numero de reinas
 * @param queens vector que indica la posicion de las reinas en el tablero
 */
void placeQueens(int n, vector<int> &queens){
	// Pone las reinas una en cada columna y en una fila aleatoria
	for (int i = 0; i < queens.size(); i++){
		queens[i] = rand() % n;
	}
}

/**
 * @brief Si se sobrepasa el límite, devuelve la posición a la que le daría la vuelta
 * Complejidad: O(1)
 * 
 * @param n tamaño del tablero y numero de reinas
 * @param row fila de la reina que se quiere mover
 * @param direction si es arriba o abajo
 * @return int índice de la fila a la que se movería
 */
int circlePositions(int n, int row, int direction) {
	if (row+direction >= n)
		return 0;
	else if (row+direction < 0)
		return n-1;
	
	return row+direction;
}

/**
 * @brief Algoritmo de Hill Climbing para el problema
 * Complejidad: O(n²*m)
 * 
 * @param n tamaño del tablero y numero de reinas
 * @param queens vector que indica la posicion de las reinas en el tablero
 */
void hillClimbing(int n, vector<int> &queens) {
	bool flag;
	int index;

	while (totalAttacks(queens) > 0) {
		for (int i = 0; i < queens.size(); i++) {
			int row = queens[i];
			int currValue = heuristicValue(row, i, queens);
			int posUp = circlePositions(n, row, 1);
			int posDown = circlePositions(n, row, -1);

			if (flag && index == i) {
				queens[i] = rand() % n;
			} else {
				if (heuristicValue(posUp, i, queens) <= currValue) {
					currValue = heuristicValue(row, i, queens);
					queens[i] = posUp;
				}
				if (heuristicValue(posDown, i, queens) <= currValue) {
					queens[i] = posDown;
				}
				if (row == queens[i]) {
					if (!flag) {
						flag = true;
						index = i;
					}
				}
			}
		}
	}
}



/********
 * Main *
 ********/
int main(){

	int n;
	cin >> n;

	vector<int> board(n, int(0)); // Tablero de ajedrez

	// Inicializa la semilla aleatoria
	srand(time(NULL));
	// Sitúa las reinas
	placeQueens(n, board);
	// Realiza la solución mediante el algortimo Hill Climbing
	hillClimbing(n, board);
	// Imprime el tablero con la solución
	printBoard(n, board);
}