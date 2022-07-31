#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxProd = 1;
        int minProd = 1;
        int ans = -15;
        int temp = 1;
        
        for (int idx=0; idx<nums.size(); idx++) {
            
            temp = maxProd;//1
            maxProd = max(nums[idx],max(maxProd * nums[idx], minProd * nums[idx]));
            minProd = min(nums[idx],min(temp * nums[idx], minProd * nums[idx]));
            
            ans = max(ans,maxProd);//0
            
            if (nums[idx] == 0) {
                maxProd = 1;
                minProd = 1;
            
            }
        }
        
        return ans;
    }
};