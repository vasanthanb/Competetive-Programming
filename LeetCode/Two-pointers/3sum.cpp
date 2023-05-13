#include <bits/stdc++.h>

using namespace std;

//brute force approach
// vector<vector<int>> threeSum(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> ans;
//     if(nums.size() < 3) {
//         return ans;
//     }
//     for(int i = 0; i < nums.size() - 2; i++) {
//         if(i > 0 && nums[i] == nums[i - 1]) {
//             continue;
//         }
//         for(int j = i + 1; j < nums.size() - 1; j++) {
//             for(int k = j + 1; k < nums.size(); k++) {
//                 if(nums[i] + nums[j] + nums[k] == 0) {
//                     ans.push_back({nums[i], nums[j], nums[k]});
//                 }
//             }
//         }
//     }
//     return ans;
// }

//two pointers approach
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    if(nums.size() < 3) {
        return ans;
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; i++) {
        if(nums[i] > 0) {
            break;
        }
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1, k = nums.size() - 1;

        while(j < k) {
            if(nums[i] + nums[j] + nums[k] < 0) {
                j++;
            }
            else if(nums[i] + nums[j] + nums[k] > 0) {
                k--;
            }
            else {
                ans.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1]) {
                    j++;
                }
                j++;
                while (j < k && nums[k - 1] == nums[k]) {
                    k--;
                }
                k--;
            }
        }
    }
    return ans;
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
    vector<vector<int>> ans = threeSum(nums);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}