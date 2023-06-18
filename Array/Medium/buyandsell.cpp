#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int miniprice=prices[0];
        for(int i=1;i<prices.size();i++){
            int currprofit=prices[i]-miniprice;
            profit=max(profit,currprofit);
            miniprice=min(miniprice,prices[i]);
        }
        return profit;
    }
};