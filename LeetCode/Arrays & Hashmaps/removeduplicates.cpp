#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    // int i = 0; //brute force approach O(n^2) due to erase()
    // while(i < nums.size()) {
    //     if(i < nums.size() - 1 and nums[i] == nums[i + 1]) {
    //         nums.erase(nums.begin() + i + 1);
    //     }
    //     else {
    //         i++;
    //     }
    // }
    // return nums.size();
    if(nums.empty()) {
        return 0;
    }
    int j = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
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
    int k = removeDuplicates(nums);
    cout << k << endl;
    for(auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}