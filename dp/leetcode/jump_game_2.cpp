#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
       
        int n = nums.size();
        
        vector<int> dp(n,0);
        
        for (int idx=n-2; idx>=0; idx--) {
            
            int val = nums[idx];
            int mn = 100001;
            
            if (val == 0) continue;
            
            while(val > 0) {
                
                int s = idx+val>=0 && val+idx<n ? dp[idx+val] : 0;
                if (s == 0 && (idx+val >= 0 && idx+val < n-1)) {
                    val--;
                    continue;
                }
                else 
                mn = min(mn,s);
                val--;
            }
            
            dp[idx] = mn+1;
        }
        
        return dp[0];
    }
};