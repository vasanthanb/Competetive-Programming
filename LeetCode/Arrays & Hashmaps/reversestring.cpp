#include<bits/stdc++.h>

using namespace std;

void reverseString(vector<char>& word) {
    // using stack
    // stack<char> s;
    // for(auto i : word) {
    //     s.push(i);
    // }
    // word.clear();
    // while(!s.empty()) {
    //     word.push_back(s.top());
    //     s.pop();
    // }

    //using swap
    int i = 0; int j = word.size() - 1;
    while(i < j) {
        swap(word[i++], word[j--]);
    }
}

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input);
    vector<char> word;
    char ch;
    while(stream >> ch) {
        word.push_back(ch);
    }
    reverseString(word);
    for(auto i : word) {
        cout << i;
    }
    cout << endl;
    return 0;
}