// Paulina Cardoso
// A01701490

#include<bits/stdc++.h>
using namespace std;
 
 // Encuentra las veces que un prefijo esta en el string
vector<int> timesRepeated(string str, int n) {
    vector<int> countRepetitions(n); // Vector para saber el contador de los prefijos en el string
    countRepetitions[0] = n;
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i >= l && i <= r) {
            countRepetitions[i]=min(countRepetitions[i-l], r-i+1);
        }
        
        while(i+countRepetitions[i] < n && str[countRepetitions[i]] == str[i+countRepetitions[i]]) {
            countRepetitions[i]++;
        }
 
 
        if(i+countRepetitions[i]-1<n && i+countRepetitions[i]-1>r) {
            l = i;
            r = i + countRepetitions[i] - 1;
        }
    }
    return countRepetitions;
}

// Checa si hay un prefijo que sea sufijo y las veces que aparecen en el string
void prefixSuffix(string str) {
    int n = str.length(); 
    vector<int> repetitions = timesRepeated(str, n); // Vector para saber el contador de los prefijos en el string
    vector<bool> preffixSuffix(n,false); // Vector booleano para saber si el prefijo de 0 a [i] tambien es un sufijo
    
    int res=0;
    
    for(int i = 0; i < n; i++) {
        if(i+repetitions[i] == n) {
            preffixSuffix[repetitions[i]] = true;
        }
    }

    vector<int> counterPrefixes(n+1,0); // Almacena las veces que el prefijo de 0 a [i] se encuentra en el string
 
    for(int i = 0; i < n; i++) {
        counterPrefixes[repetitions[i]]++;
    }
    
    
    for(int i = n-1; i >= 0; i--) {
        counterPrefixes[i] += counterPrefixes[i+1];
    }
 

    bool flag = false;
    for (int i = n; i >= 1; i--) {
        if(preffixSuffix[i] == true && counterPrefixes[i] > 2) { // Si encuentra un sufijo que sea prefijo y se repite minimo 3 veces en el string, es la contrasena
            cout << str.substr(0, i); // Imprime la contrasena
            flag = true;
            break; 
        }
    }
    if (!flag) { // No hay contrasenia
        cout << "Just a legend" << endl;
    }
    
}

int main() {
    string str;
    cin >> str;
    prefixSuffix(str);
}