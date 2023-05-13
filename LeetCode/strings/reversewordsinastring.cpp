#include<bits/stdc++.h>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input);
    string word;
    vector<string> words;
    while (stream >> word) {
        words.push_back(word);
    }
    string ans = "";
    for(int i = words.size() - 1; i >= 0; i--) {
        if(i != words.size() - 1) {
            ans += " "; 
        }
        ans += words[i];
    }
    cout << ans << endl;
    return 0;
}