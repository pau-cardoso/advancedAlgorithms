#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <stdio.h>
using namespace std;
 
const int INF = 923460123; // Constate para determinar cuando la conexión no es existente 


/**********************
* Algoritmo Dijkstra
***********************/
int dijkstra(int n, vector<vector<int>> pesos,int inicio, int destino){
  vector<bool> visitados(n+1, false); // Vector para los nodos ya visitados

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>> > Q; // Priority queue ordenado de pesos minimos al principio
  Q.push({0, inicio}); // Se inicia con un peso de 0 en el nodo inicio

  while( !Q.empty() ){ 

    pair<int,int> primero = Q.top();
    Q.pop();

    int nodoPeso = primero.first;
    int nodoVal = primero.second;

	if (nodoVal == destino) return nodoPeso; // Si llegamos al nodo destino, regresa el peso minimo

    if(!visitados[nodoVal]){ // Verificamos si el nodo aun no fue visitado
      visitados[nodoVal] = true;

      for(int i = 0; i <n; i++){
        if (pesos[nodoVal][i] != 0 && pesos[nodoVal][i] != INF) {
			    Q.push({nodoPeso + pesos[nodoVal][i], i}); // Se agrega al queue los vecinos del nodo actual
		}
      }
    }
  }
  return INF; // No hubo conexiones entre los nodos inicio y final
}


/***************************
* Algoritmo Floyd Warshall
****************************/
vector<vector<int>> Floyd_Warshall (int n, vector<vector<int>> dist){
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // Comparamos el peso del nodo
            }
        }
    }
    return dist;
}


/**************
* Codigo main
***************/
int main() {
  
  int n, m;
  cin >> n >> m;
  vector<vector<int>> pesos (n);
  
  for (int i = 0; i < n; i++) { // ingresamos los valores a la matriz de pesos
    for(int j = 0; j < n; j++){
      pesos[i].push_back(INF); // En caso de no existir una conexión se dará el valor de la constante
    }
  }
  
  int u, v, x;
  for (int i = 0; i < m; i++) { // ingresamos los valores a la matriz de pesos
    cin >> u >> v >> x;
    x = pow(2, x);
    pesos[u][v] = x;
  }

  int src, dest;
  cin >> src >> dest;

  cout<<"\nDijkstra:\n"; // Algoritmo de Dijkstra
  int sol = dijkstra(n, pesos, src, dest);
  cout << "Solution: " << sol << endl;

//   for (int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       int sol = dijkstra(n, pesos, i, j);
//       if(i != j){
//         cout << "node " << i+1 << " to node " << j+1 << ": " << sol << endl;
//       }
// 		}
//   }
  
//   cout<<"\nFloyd:\n"; // Algoritmo de Floyd
//   vector<vector<int>> floyd = Floyd_Warshall(n, pesos);
//   for (int i = 0;i < n; i++){
//     for(int j = 0; j < n; j++){
//       if(i==j){
//         cout <<"0 ";
//       }
//       else{
//         cout << floyd[i][j] << " "; 
//       }
//     }
//     cout << endl;
//   }
  
  return 0;
}