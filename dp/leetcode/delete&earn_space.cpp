#include<iostream>
#include<vector>
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
        
        int maxNumber = -1;
        
        for (auto it=mp.begin(); it!=mp.end(); it++) {
            int val = it->first;
            
            maxNumber = max(maxNumber,val);
        }
        
        int twoBack = 0;
        int oneBack = (mp.find(1)!=mp.end()) ? mp[1] : 0;
        
        for (int idx=2; idx<=maxNumber; idx++) {
            int gain = (mp.find(idx)!=mp.end()) ? mp[idx]*idx : 0;
            int mxVal = max(gain+twoBack,oneBack);
            
            twoBack = oneBack;
            oneBack = mxVal;
        }
        
        return oneBack;
    }
};