class Solution {
public:
    int bulbSwitch(int n) {
        int ans=0;
        int i=1;
        while(i*i <= n){
            i++;
            ans++;
        }
        return ans;
    }
};