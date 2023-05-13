#include<bits/stdc++.h>

using namespace std;

//iteration
// void insertion_sort(vector<int>& array) {
//     for(int i = 1; i < array.size(); i++) {
//         int k = array[i];
//         int j = i - 1;
//         while(j >= 0 && array[j] > k) {
//             array[j + 1] = array[j];
//             j--;
//         }
//         array[j + 1] = k;
//     }
// }

//recursion
void insertion_sort(vector<int>& array, int i, int n) {
    if(i == n) {
        return;
    }
    int k = array[i];
    int j = i - 1;
    while(j >= 0 && array[j] > k) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = k;
    insertion_sort(array, ++i, n);
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
    insertion_sort(array, 1, array.size());
    for(auto i : array) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}