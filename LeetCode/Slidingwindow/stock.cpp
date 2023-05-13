#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> prices) {
    int l = 0, r = 0, profit = 0;
    while(r < prices.size()) {
        if(prices[l] < prices[r]) {
            profit = max(profit, prices[r] - prices[l]);
        }
        else {
            l = r;
        }
        r++;
    } 
    return profit;
}

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input);
    vector<int> prices;
    int price;
    while(stream >> price) {
        prices.push_back(price);
    }

    int profit = maxProfit(prices);
    cout << profit << endl;
}
