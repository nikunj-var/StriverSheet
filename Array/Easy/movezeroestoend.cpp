#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int left = 0;
        int right = 0;
        while(right < n){
            if(arr[right] != 0){
               swap(arr[left],arr[right]); 
                left++;
            }
            right++;
        }
    }
};