#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n,0);
        
        for (int idx=1; idx<n; idx++) {
            
            int val = nums[n-idx-1];
            if (val == 0) {
                dp[idx] = 0;
                continue;
            }
            int diff = idx-val;
            
            if (diff >=0) {
                int it = 1;
                int mx = -1;
                
               
                while(it <= val) {
                    int val1 = idx-it >=0 && idx-it<n ? it + dp[idx-it] : 0; 
                    dp[idx] = max(dp[idx],val1);
                    it++;
                }
            }
            else {
                dp[idx] = idx;
            }
            
        }
        
        if (dp[n-1] == n-1)return true;
        else return false;
    }
};