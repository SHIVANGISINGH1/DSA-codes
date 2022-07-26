// very sparsly located intervals like [2,9000,1,56]
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
public: 
    
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
        
        vector<int> dp(mp.size(),0);
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int val = it->first;
            dp.push_back(val);
        }
        
        sort(dp.begin(), dp.end());
        
        int twoBack = 0;
        int oneBack = mp[dp[0]] * dp[0];
        
        for (int idx=1; idx<dp.size(); idx++) {
            
            int gain = mp[dp[idx]]*dp[idx];
            int temp = oneBack;
            
            if (dp[idx]-dp[idx-1] == 1) {
                
                int val = max(gain+twoBack,oneBack);
                oneBack = val;
            }
            else {
                oneBack += gain; 
            }
            
            twoBack = temp;
        }
        return oneBack;
    }
};