#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> spiralmatrix;
    int left = 0; int right = matrix[0].size() - 1;
    int top = 0; int bottom = matrix.size() - 1;
    while(left <= right && top <= bottom) {
        for(int i = left; i <= right; i++) {
            spiralmatrix.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++) {
            spiralmatrix.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                spiralmatrix.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                spiralmatrix.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return spiralmatrix;
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
    vector<int> spiralmatrix = spiralOrder(matrix);
    for(auto i : spiralmatrix) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}