
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int numberOfOperations(string A, string B, int m, int n){

    if (A == B) 
        return 0;

    int lengthSubstring = 0;
 
    int matrix[m + 1][n + 1];
    memset(matrix, 0, sizeof(matrix));
 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
                if (matrix[i][j] > lengthSubstring) {
                    lengthSubstring = matrix[i][j];
                }
            }
        }
    }
    return m+n - (lengthSubstring)*2;
}


int main() {

    int testCases;
    string a, b;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cin >> a;
        cin >> b;
        cout << numberOfOperations(b, a, b.size(), a.size()) << endl;
    }
    return 0;
}
