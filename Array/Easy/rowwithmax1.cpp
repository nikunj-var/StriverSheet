#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int j=m-1;
	    int maxi=0;

	    for(int i=0;i<n;i++){
	        bool flag=false;
	        while(j >= 0 && arr[i][j] == 1){
	            j--;
	            flag = true;
	        }
	        if(flag){
	            maxi = i;
	        }
	    }
	    if(maxi == 0 && arr[0][m-1] == 0){
	        return -1;
	    }
	    return maxi;
	}

};