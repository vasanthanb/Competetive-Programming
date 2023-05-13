#include<bits/stdc++.h>

using namespace std;

void selection_sort(vector<int>& array) {
    for(int i = 0; i < array.size() - 1; i++) {
        int min = i;
        for(int j = i; j < array.size() ; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }
        swap(array[i], array[min]);
    }
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
    selection_sort(array);
    for(auto i : array) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}