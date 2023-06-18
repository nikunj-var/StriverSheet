#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
       int ans=0;
       for(auto i:arr){
           ans^=i;
       }
       for(int i=1;i<=n;i++){
           ans ^= i;
       }
       return ans;
    }
};