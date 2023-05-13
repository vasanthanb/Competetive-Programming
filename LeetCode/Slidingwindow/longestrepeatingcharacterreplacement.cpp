#include<bits/stdc++.h>

using namespace std;

int characterReplacement(string s, int k) {
    unordered_map<char, int> map;
    int l = 0; int r = 0; int maxcount = 0; int maxlen = 0;
    while(r < s.size()) {
        maxcount = max(maxcount, ++map[s[r]]);
        if(((r - l + 1) - maxcount) > k) {
            map[s[l]]--;
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main() {
    string input;
    int k;
    getline(cin,input);
    cin >> k;
    cout << characterReplacement(input, k) << endl;
    return 0;
}