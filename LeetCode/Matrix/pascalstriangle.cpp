#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> pascaltriangle(int rows) {
    vector<vector<int>>pascal(rows);
    for(int i = 0; i < rows; i++) {
        pascal[i].resize(i + 1);
        pascal[i][0] = pascal[i][i] = 1;
        for(int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
    return pascal;
}

int main() {
    int rows;
    cout << "Enter the number of rows : ";
    cin >> rows;
    vector<vector<int>> pascal = pascaltriangle(rows);
    for(auto i : pascal) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}