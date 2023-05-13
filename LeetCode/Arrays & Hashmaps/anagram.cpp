#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
    // if(s.size() != t.size()) {
    //     return false;
    // }
    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());
    // return s == t;

    if(s.size() != t.size()) {
        return false;
    }
    unordered_map<char, int> map;
    for(int i = 0; i < s.size(); i++) {
        map[s[i]]++;
        map[t[i]]--;
    }
    for(auto [key, value] : map) {
        if(value != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    bool ans = isAnagram(s,t);
    cout << ans;
}