#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
     
    int helper(int startingIdx, int endingIdx, vector<int>& nums) {
        
        int n = endingIdx - startingIdx + 1;
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = nums[startingIdx];
        
        for (int idx=2; idx<n; idx++) {
            
            int val = startingIdx == 0 ? idx-1 : idx;
            int m1 = dp[idx-2] + nums[val];
            int m2 = dp[idx-1]; 
            int m3 = nums[val]; 
            
            dp[idx] = max(m1, max(m2,m3)); 
        }
        
        return dp[n-1];
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        int r1 = helper(0,n-1,nums);
        int r2 = helper(1,n,nums);
        
        return max(r1,r2);
    }
};