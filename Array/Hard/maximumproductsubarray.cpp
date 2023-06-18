#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
// in two passes
    int maxProduct(vector<int> arr) {
        int  n=arr.size();
        int  product=1;
	    int  maxi=INT_MIN;
	    

	    for(int i=0;i<n;i++){
	        product*=arr[i];
	        maxi=max(product , maxi);
	        if(product == 0)
	            product=1;
	    }
	    product=1; 
	    for(int i=n-1;i>=0;i--){
	        product*=arr[i];
	        maxi=max(product , maxi);
	        if(product == 0)
	            product=1;
	    }
	    return maxi;
    }
};


//IN one pass
class Solution {
public:
    int maxProduct(vector<int> arr) {
        int  n=arr.size();
        int  l=1,r=1;
	    int  maxi=INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        l*=arr[i];
            r*=arr[n-i-1];
	        maxi=max(max(l,r) , maxi);
	        if(l == 0)
                l=1;
            if(r == 0)
                r=1;    
	    }
	   
	    return maxi;
    }
};