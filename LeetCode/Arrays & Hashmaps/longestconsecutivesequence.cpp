#include<bits/stdc++.h>
#include<string>
#include<sstream>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 1) {
        return 1;
    }
    unordered_set<int> set(nums.begin(), nums.end());
    int longest = 0;
    for(auto i : nums) {
        if(set.find(i - 1) == set.end()) {
            int length = 0;
            while (set.find(i + length) != set.end()) {
                length++;
            }
            longest = max(length, longest);
        }
    }
    return longest;
}

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input); //getting input as string and converting into a stringstream

    vector<int> nums;
    int num;

    while (stream >> num) {     // ">>" reading the element from stringstream
        nums.push_back(num);
    }
    int length = longestConsecutive(nums);
    cout << length << endl;
}
