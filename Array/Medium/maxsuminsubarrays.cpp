#include<iostream>
using namespace std;
class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
       long long sum = 0;
       long long maxi = LONG_MIN;
       for(int i = 0 ; i< N-1;i++ ){
           sum = arr[i] + arr[i+1];
           maxi = max(maxi,sum);
       }
       return maxi;
    }
};