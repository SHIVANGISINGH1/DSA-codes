#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int , bool> mp;
        int len = nums.size();
        
        for (int idx=0; idx<len; idx++) {
            if (mp.count(nums[idx]) > 0) continue;
            mp.insert({nums[idx], true});
        }
        
         unordered_map<int , bool>:: iterator it = mp.begin();
        
         while(it != mp.end()) {
             int val = it->first;
             
             if (mp.count(val-1) > 0) {
                 it->second = false;
             }
             it++;
         }
        
         
         unordered_map<int , bool>:: iterator it1 = mp.begin();
        
         int maxLen = 0;
        
         while(it1 != mp.end()) {
        
             if (it1->second == true) {
                 
                 int val = it1->first;
                 int i = 1;
                 
                 while(mp.count(val + i)) {
                     i++;
                 }
                 
                 if (i > maxLen) {
                     maxLen = i;
                 }
             }
             
             it1++;
             
         }
        return maxLen;
    }
};