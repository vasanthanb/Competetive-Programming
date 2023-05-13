#include<bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    //Transpose
    int n = matrix.size();
    for(int i = 0; i <= n - 2; i++) {
        for(int j = i + 1; j <= n - 1; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //reverse
    for(int i = 0; i <= n - 1; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int> (n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    rotate(matrix);
    for(auto i : matrix) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}