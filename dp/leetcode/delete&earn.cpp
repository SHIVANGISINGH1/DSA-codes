// Recursive memoized solution
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    
    int helper(int n, unordered_map<int,int> &mp, unordered_map<int,int> &dp) {
        
        if (n == 0) return 0;
        if (n == 1) {
            return (mp.find(1)!=mp.end()) ? mp[1] : 0; 
        }
        
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        
        int gain = (mp.find(n)!= mp.end()) ? mp[n] * n : 0; 
        int m1 = gain + helper(n-2, mp, dp); 
        int m2 = helper(n-1, mp, dp);  
        
        int val = max(m1,m2); 
        dp.insert({n,val});
        
        return dp[n]; 
    }
    
    
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for (int idx=0; idx<n; idx++) {
            
            if (mp.find(nums[idx]) != mp.end()) {
                int val = mp[nums[idx]];
                mp[nums[idx]] = val+1;
            }
            else {
                mp.insert({nums[idx], 1});
            }
        }
        
        int maxNumber = -1;
        
        for (auto it=mp.begin(); it!=mp.end(); it++) {
            int val = it->first;
            
            maxNumber = max(maxNumber,val);
        }
        
        unordered_map<int,int> dp;
        return helper(maxNumber, mp, dp);
    }
};