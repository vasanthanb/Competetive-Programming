#include<bits/stdc++.h>

using namespace std;

//permutations in arrays
void recursivepermutation(vector<vector<int>>& permutations, vector<int>& permutation, unordered_map<int, int>& map, vector<int>& nums) {
    if(permutation.size() == nums.size()) {
        permutations.push_back(permutation);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(!map[nums[i]]) {
            permutation.push_back(nums[i]);
            map[nums[i]] = 1;
            recursivepermutation(permutations, permutation, map, nums);
            permutation.pop_back();
            map[nums[i]] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    unordered_map<int, int> map;
    vector<int> permutation;
    recursivepermutation(permutations, permutation, map, nums);
    return permutations;
}

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input);
    vector<int> nums;
    int num;
    while(stream >> num) {
        nums.push_back(num);
    }
    vector<vector<int>> permutations = permute(nums);
    for(auto i : permutations) {
        for(auto j : i) {
            cout << j << " "; 
        }
        cout << " ";
    }
    cout << endl;
    return 0;    
}