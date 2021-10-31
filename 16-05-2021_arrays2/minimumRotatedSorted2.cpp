class Solution {
public:
    int findMin(vector<int>& nums) 
{
    int left = 0;
    int right = nums.size()-1;
        
    while (left<right)
    {
        int mid = left + (right-left)/2;
        
        if (nums[right]<nums[mid])
        {        
            left = mid+1;
        }
        else if (nums[mid]<nums[right]||nums[mid]>nums[left]) 
        {  
            right = mid;
        } 
        else       //  if our mid ele is equal to right or left we will just dec the right 
        {    
            right--;
        }
    } 
         return nums[left];
}
};