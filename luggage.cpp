#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

bool knapsackAlgorithm(vector<int> weights, int sum) {
    int n = weights.size();
    int m = sum / 2;
    int mat[n][m + 1];
    fill( *mat, *mat + (n)*(m+1), 0);
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<=m; j++) {
            if ( j<weights[i] ) {
                mat[i][j] = mat[i - 1][j];
            }
            else {
                mat[i][j] = max(weights[i] + mat[i-1][j-weights[i]], mat[i -1][j]);
            }
        }
    }
    if(mat[n-1][m] = sum/2) {
        return true;
    }
    return false;
}

int main() {
    int n;
    string usrInput = "";
    getline(cin, usrInput);
    n = stoi(usrInput);

    for(int i = 0; i<n; i++) {
        int sum = 0;
        getline(cin, usrInput);
        vector<int> weights;
        stringstream s(usrInput);
        string num;
        int temp;

        while (s >> num) {
            temp = stoi(num);
            sum + temp;
            weights.push_back(temp);
        }

        if (sum % 2 == 0){
            if(knapsackAlgorithm (weights, sum))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        cout << "NO" << endl;
    
    return 0;
    }
}
