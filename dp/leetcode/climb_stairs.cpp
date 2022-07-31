#include<iostream>
#include<vector>
using namespace std;


// same as pepcoding 
class Solution {
public:
    int climbStairs(int n) {
       
        vector<int> dp(n+1,0);
        
        dp[0] = 1;
        
        for (int idx=1; idx<=n; idx++) {
            
            int p1 = idx>=1 ? dp[idx-1] : 0; // 1 1 2
            int p2 = idx>=2 ? dp[idx-2] : 0; // 1 1
            
            dp[idx] = p1+p2; // 1->1 2->2 3->3
        }
        
        return dp[n];
        
    }
};