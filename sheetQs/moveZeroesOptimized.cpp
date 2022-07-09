#include<iostream>
#include<vector>
using namespace std;


// Here we will maintain two pinters left and right 
// Left is initial at 0 index and right is also at 0 
// as we see a non zero ele we swap left with it and inc left and right both 
// in this way left will be pointing to the first zero ele pointing before right

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        int left = 0;
        
        for (int right=0; right<nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left++], nums[right]);
            }
        }
        
    }
};