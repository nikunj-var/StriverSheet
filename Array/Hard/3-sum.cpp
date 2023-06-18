#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;
        
        if(arr.size() == 0)
            return ans;
        
        for(int i=0;i<arr.size()-2;i++){
            if(i!=0 && arr[i] == arr[i-1])
                continue;
            
            int low=i+1;
            
            int high=arr.size()-1;
            
            while(low < high){
                
                int sum=arr[i] + arr[low] + arr[high];
                
                if(sum == 0){
                
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    ans.push_back(temp);
                    low++;
                    high--;
                    while(low<high && arr[low] == arr[low-1])
                        low++;
                    while(low<high && arr[high] == arr[high+1])
                        high--;
                }
             
                else if(sum < 0)
                    low++;
                
                else
                    high--;
            }
        }
        return ans;
    }
};