#include<bits/stdc++.h>

using namespace std;

//iteration
// void bubble_sort(vector<int>& array) {
//     for(int i = array.size() - 1; i >= 0; i--) {
//         for(int j = 0; j < i; j++) {
//             if(array[j] > array[j + 1]) {
//                  swap(array[j], array[j + 1]);
//             }
//         }
//     }
// }

//recursion
void bubble_sort(vector<int>& array, int n) {
    if(n == 1) {
        return;
    }
    for(int j = 0; j < n - 1; j++) {
        if(array[j] > array[j + 1]) {
            swap(array[j], array[j + 1]);
        }
    }
    bubble_sort(array, n - 1);
}

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input);
    vector<int> array;
    int element;
    while (stream >> element) {
        array.push_back(element);
    }
    bubble_sort(array, array.size());
    for(auto i : array) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}