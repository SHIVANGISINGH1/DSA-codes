#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n,0);
        
        dp[0] = nums[0];
        
        int ans =  nums[0];
        
        for (int idx=1; idx<n; idx++) {
            
            int m1 = nums[idx] + (idx-2>=0 ? dp[idx-2] : 0);
            int m2 = dp[idx-1];
            
            ans = max(ans, max(m1,m2));
            dp[idx] = ans;
        }
        
        return ans;
    }
};
