// Paulina Cardoso Fuentes
// A01701490

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Revisa si la posicion en la que se quiere poner una reina es posible
 * Complejidad: O(n)
 * 
 * @param row fila en la que se quiere poner la reina
 * @param col columna en la que se quiere poner la reina
 * @param board tablera con los espacios vacíos y con las reinas
 * @return true si se puede colocar una reina en la posicion, false si no se puede colocar
 */
bool isValid(int row, int col, vector<vector<bool>> board){
	// Checa si hay alguna reina en la columna dada
	for(int i = 0; i < col; i++){
		if(board[row][i]){
			return false;
		}
	}

	// Checa si hay alguna reina en la diagonal superior
	for(int i = row, j = col; i >= 0 and j >= 0; i--, j--){
		if(board[i][j]){
			return false;
		}
	}

	// Checa si hay alguna reina en la diagonal inferior
	for(int i = row, j = col;  i < board.size() and j >= 0; i++, j--){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}


/**
 * @brief Función recursiva que posiciona las reinas en el tablero
 * Complejidad O(n²)
 * 
 * @param n Tamaño del tablero y reinas requeridas
 * @param queensPlaced número de reinas colocadas hasta al momento
 * @param board tablero con los espacios vacíos y las reinas colocadas
 * @return bool - true si aún se puede continuar colocando reinas, false si ya se han colocado todas 
 */
bool placeQueen(int n, int queensPlaced, vector<vector<bool>> &board){
  
	// Si todas las reinas se colocaron correctamente devuelve true
	if(queensPlaced == n)
		return true;

	// Revisa fila por fila si la reina se puede situar en esa casilla 
	for(int i = 0; i < n; i++){
		if(isValid(i, queensPlaced, board)){
			board[i][queensPlaced] = true;
			
			// Revisa recursivamente la posición todas las reinas 
			if(placeQueen(n, queensPlaced + 1, board)){
				return true;
			}
			// No se puede situar la reina en esa posición
			else{
				board[i][queensPlaced] = false;
			}
		}
	}
	return false;
}

/********
 * Main *
 ********/
int main(){

	int n, queens = 0;
	cin >> n;

	vector<vector<bool>> board(n, vector<bool> (n, false)); // Tablero de ajedrez

	// Sitúa las reinas
	placeQueen(n, queens, board); 

	// Imprime la solución
	for(int i = 0; i < board.size(); i++){
		cout << "{ ";
		for(int j = 0; j < board.size(); j++){
			if(j == board.size()-1){
			cout << board[i][j] << " ";
			}
			else{
			cout << board[i][j] << ", ";
			}
		}
		cout << "}" << endl;
	}
}