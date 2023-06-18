#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> newp;
        int l=matrix.size();
          newp=matrix;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
               newp[i][j]=matrix[j][i]; 
            }
        }
            matrix=newp;
            for(int i=0;i<l;i++)
            {
                for(int j=0;j<l/2;j++){
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[i][l-j-1];
                    matrix[i][l-j-1]=temp;
                }
            }
         
    }
};