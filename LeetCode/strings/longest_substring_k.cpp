//C++ program to solve the problem  Longest Substring with At Least K Repeating //Characters
#include <bits/stdc++.h>
using namespace std;

// brute-force approach
/*
int longestSubstring(string s, int k) {
    if (s.size() <  k) {
        return 0;
    }
    int len = 0;
    for (int i = 0; i < s.size(); i++) {
        unordered_map<char, int> map;
        for (int j = i; j < s.size(); j++) {
            if (map.find(s[j]) != map.end()) { // if duplicate present
                map[s[j]]++;
            }
            else {
                map[s[j]] = 1;
            }
            bool freq = 1;
            for (auto [key, value] : map) {
                if (value != 0 && value < k) {
                    freq = 0;
                }
            }
            if (freq) { 
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}
*/

// optimized approach
/*
int longestSubstring(string s, int k) {
    int countMap[26];
    int maxUnique = getMaxUniqueLetters(s);
    int result = 0;
    for (int currUnique = 1; currUnique <= maxUnique; currUnique++) {
        // reset countMap
        memset(countMap, 0, sizeof(countMap));
        int windowStart = 0, windowEnd = 0, idx = 0, unique = 0, countAtLeastK = 0;
        while (windowEnd < s.size()) {
            // expand the sliding window
            if (unique <= currUnique) {
                idx = s[windowEnd] - 'a';
                if (countMap[idx] == 0) unique++;
                countMap[idx]++;
                if (countMap[idx] == k) countAtLeastK++;
                windowEnd++;
            }
            // shrink the sliding window
            else {
                idx = s[windowStart] - 'a';
                if (countMap[idx] == k) countAtLeastK--;
                countMap[idx]--;
                if (countMap[idx] == 0) unique--;
                windowStart++;
            }
            if (unique == currUnique && unique == countAtLeastK)
                result = max(windowEnd - windowStart, result);
            }
        }
    return result;
}

// get the maximum number of unique letters in the string s
int getMaxUniqueLetters(string s) {
    bool map[26] = {0};
    int maxUnique = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!map[s[i] - 'a']) {
            maxUnique++;
            map[s[i] - 'a'] = true;
        }
    }
    return maxUnique;
}


*/
///*
bool each(int l, int r, string s, int k) {
    if ((r - l + 1) < k) {
        return false;
    }
    unordered_map<char, int> map2;
    for(int i = l; i <= r; i++) {
        if (map2.find(s[i]) != map2.end()) {
            map2[s[i]]++;
        }
        else {
            map2[s[i]] = 1;
        }
    }
    for (auto [key, value] : map2) {
        if (value != 0 && value < k) {
            return false;
        }
    }
    return true;
}

int longestSubstring(string &s, int k){
    if (s.size() == 0 || k > s.size()) {
        return 0;
    }
    int len = 0;
    unordered_map<char, int> map;
    vector<int> countMap(26, 0);
    for(int i = 0; i < s.size(); i++) {
        if (map.find(s[i]) != map.end()) {
            map[s[i]]++;
        }
        else {
            map[s[i]] = 1;
        }
    }
    int l = 0, r = 0;
    while(r < s.size()) {
        if(map[s[r]] < k) {
            l = r + 1;
        }
        else {
            if(each(l, r, s, k)) {
                len = max(len, r - l + 1);
            }
        }
        r++;
    }
    return len;
}


//*/

int main() {
    // string s
	string s = "bbaaacbd";
	// k
	int k = 3;

	//find the answer
	cout << "The longest substring having atleast k frequency of each unique character is: "<< longestSubstring(s, k) << endl;
	return 0;
}