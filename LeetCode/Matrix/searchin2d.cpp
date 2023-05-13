#include<bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int row = mid / n;
        int col = mid % n;
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
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
    int target;
    cin >> target;
    cout << searchMatrix(matrix, target);
    return 0;
}