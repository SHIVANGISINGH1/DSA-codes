#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        int zeroes = 0;
        int count = 0;
        
        for (int idx=0; idx<nums.size(); idx++) {
            
            if (nums[idx] != 0) {
                nums[count] = nums[idx];
                count++;
            }
        }
        
        
        while(count < nums.size()) {
            nums[count] = 0;
            count++;
        }
        
    }
};