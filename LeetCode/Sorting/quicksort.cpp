#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>& array, int start, int end) {
    int pivot = array[end];
    int p = start;
    for(int i = start; i < end; i++) {
        if(array[i] <= pivot) {
            swap(array[i], array[p]);
            p++;
        }
    }
    swap(array[p], array[end]);
    return p;
}

void quick_sort(vector<int>& array, int start, int end) {
    if(start < end) {
        int p = partition(array, start, end);
        quick_sort(array, start, p - 1);
        quick_sort(array, p + 1, end); 
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
    quick_sort(array, 0 , array.size() - 1);
    for(auto i : array) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}