#include<bits/stdc++.h>

using namespace std;

//iteration
// int search(vector<int>& nums, int target) {
//     int l = 0, r = nums.size() - 1;
//     while(l <= r) {
//         int mid = l + (r - l) / 2;
//         if(nums[mid] == target) {
//             return mid;
//         }
//         else if(nums[mid] < target) {
//             l = mid + 1;
//         }
//         else {
//             r = mid - 1;
//         }
//     }
//     return -1;
// }

//recursion
int search(vector<int>& nums, int target, int l, int r) {
    int mid = l + (r - l) / 2;
    if(nums[mid] == target) {
        return mid;
    }
    else if(nums[mid] < target) {
        l = mid + 1;
        return search(nums, target, l, r);
    }
    else {
        vector<int> right(nums.begin() + mid, nums.end());
        r = mid - 1;
        return search(right, target, l, r);
    }
    return -1;
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
    int target;
    cin >> target;
    cout << search(nums, target, 0, nums.size() - 1);
    cout << endl;
}