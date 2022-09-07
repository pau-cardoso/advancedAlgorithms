#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Funcion helper para el algoritmo KMP, donde se realiza un vector del patrón que se busca en el mensaje para no recorrer caracteres de nuevo
 * 
 * @param pattern - patrón que se busca en el mensaje
 * @param n - tamaño del patrón buscado
 * @param prefixArray - vector donde se guardará las ocurrencias en común para analizar posteriormente
 */
void prefixArray(string pattern, int n, vector<int>& prefixArray) {
    int length = 0;
    prefixArray.push_back(0);
    
    for (int i = 1; i < n; i++){
        if (pattern[i] == pattern[length]) {
            length++;
            prefixArray.push_back(length);    
        }else {
            if(length != 0) {
                length = prefixArray[length - 1];
                i--; 
            } 
            else
                prefixArray.push_back(0);
        }
    }   
}

/**
 * @brief Algoritmo KMP para encontrar un patrón en un mensaje, regresando la posición en la que se encuentra
 * 
 * @param message - mensaje en donde se busca el patrón
 * @param pattern - patrón que se busca dentro del mensaje
 */
void KMP(string message, string pattern){

    int N = message.size(), M = pattern.size();
    vector<int> prefArray, positions;
    prefixArray(pattern, M, prefArray);

    int i =0, j=0;

    while(i < N) {
        if (message[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) 
                j = prefArray[j-1];
            else 
                i++;
        }
        if (j == M) { 
            positions.push_back(i-j+1);
            j = prefArray[j-1];
        }
    }

    if(positions.size() > 0){
        cout << positions.size() << endl;
        for (int i = 0; i < positions.size(); i++){
            cout <<positions[i] <<" ";
        }
        cout<<endl;
    }
    else cout<<"Not Found"<<endl;
}

int main() {
    int testCases;
    string str, pattern;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        cin >> str;
        cin >> pattern;
        KMP(str, pattern);
    }
    
    return 0;
}