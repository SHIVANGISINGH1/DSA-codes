#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
        int n = cost.size();
        
        vector<int> dp(n+1,0);
        
        dp[n] = 0;
       
        
        for (int idx=n-1; idx>=0; idx--) {
              
            
            int p1 = idx+1<=n ? cost[idx] + dp[idx+1] : cost[idx]; //3
            int p2 = idx+2<=n ? cost[idx] + dp[idx+2] : cost[idx]; //2
            
            dp[idx] = min(p1,p2);
        }
        
        return min(dp[0],dp[1]);
    }
};