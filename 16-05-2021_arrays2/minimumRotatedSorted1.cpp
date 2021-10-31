class Solution {
public:
    int findMin(vector<int>& nums) 
{
    int left = 0;
    int right = nums.size()-1;
        
    while (left<right)
    {
        int mid = left + (right-left)/2;

        if (nums[right]<nums[mid]) // this will check if smallest element is in right or not (sorted)
        {
            left = mid+1;
        }
        else 
        {    
            right = mid;
        }    
    }

        return nums[right]; //  will return right or left as they will point to the same element  
}
};