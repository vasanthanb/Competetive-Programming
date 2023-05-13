#include<bits/stdc++.h>

using namespace std;

void setZeros(vector<vector<int>>& matrix) {
    vector<int> row(matrix.size(), 1);
    vector<int> coloum(matrix[0].size(), 1);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] == 0) {
                row[i] = 0;
                coloum[j] = 0;
            }
        }
    }
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if(row[i] == 0 or coloum[j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int row, col;
    cin >> row;
    cin >> col;
    vector<vector<int>> matrix(row, vector<int> (col));
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "matrix" << endl;
    for(auto i : matrix) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    setZeros(matrix);
    cout << "after setzeros" << endl;
    for(auto i : matrix) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}