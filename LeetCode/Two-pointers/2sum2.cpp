#include<bits/stdc++.h>

using namespace std;

vector<int>twoSum(vector<int>& numbers, int target) {
    //using map
    // vector<int> ans;
    // unordered_map<int, int> map;
    // for(int i = 0; i < numbers.size(); i++) {
    //     if(map.find(target - numbers[i]) != map.end()) {
    //         ans.push_back(map[target - numbers[i]]);
    //         ans.push_back(i + 1);
    //     }
    //     map[numbers[i]] = i + 1;
    // }
    // return ans;

    //two pointers
    vector<int> ans;
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if(sum > target) {
            r--;
        }
        else if(sum < target) {
            l++;
        }
        else {
            ans.push_back(l + 1);
            ans.push_back(r + 1);
            return ans;
        }
    }
    return ans;
}

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input);
    vector<int>numbers;
    int num;
    while (stream >> num) {
        numbers.push_back(num);
    }
    int target;
    cin >> target;
    vector<int> ans = twoSum(numbers, target);
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}