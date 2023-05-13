#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& left, vector<int>& right, vector<int>& array) {
    int i = 0; int j = 0; int k = 0;
    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) {
            array[k] = left[i];
            k++;
            i++;
        }
        else {
            array[k] = right[j];
            k++;
            j++;
        }
    }
    while(i < left.size()) {
        array[k] = left[i];
        k++;
        i++;
    }
    while(j < right.size()) {
        array[k] = right[j];
        k++;
        j++;
    }
}

void merge_sort(vector<int>& array) {
    if(array.size() <= 1) {
        return;
    }
    int mid = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + mid);
    vector<int> right(array.begin() + mid, array.end());
    merge_sort(left);
    merge_sort(right);
    merge(left, right, array);  
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
    merge_sort(array);
    for(auto i : array) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}