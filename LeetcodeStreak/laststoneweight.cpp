#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0)
            return 0;
        if(stones.size()==1)
            return stones[0];
        sort(stones.begin(),stones.end());
        int temp=stones[stones.size()-1]-stones[stones.size()-2];
        int n=stones.size()-1;
        stones.erase(stones.begin()+n);
        stones.erase(stones.begin()+n-1);
        if(temp!=0)
            stones.push_back(temp);
        return lastStoneWeight(stones);
    }
};