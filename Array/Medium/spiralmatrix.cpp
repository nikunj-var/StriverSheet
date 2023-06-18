#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> ans;
        
        int rowstart=0,colstart=0;
        int rowend=row-1;
        int colend=col-1;
        
        while(rowstart<=rowend && colstart <= colend){
            
            for(int i=colstart;i<=colend;i++){
                ans.push_back(matrix[rowstart][i]);
            }
            rowstart++;
            
            if(ans.size() >= row*col){
                break;
            }
            
            for(int i=rowstart;i<=rowend;i++){
                ans.push_back(matrix[i][colend]);
            }
            colend--;  
            
            if(ans.size() >= row*col){
                break;
            }
            
            for(int i=colend;i>=colstart;i--){
                ans.push_back(matrix[rowend][i]);
            }
            rowend--;
            
            if(ans.size() >= row*col){
                break;
            }
            
            for(int i=rowend;i>=rowstart;i--){
                ans.push_back(matrix[i][colstart]);
            }
            colstart++;
            
            if(ans.size() >= row*col){
                break;
            }
            
        }
        return ans;       
    }
};