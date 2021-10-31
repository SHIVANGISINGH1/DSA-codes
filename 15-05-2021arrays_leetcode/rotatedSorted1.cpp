class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
    int left = 0;
    int right = nums.size()-1;
    int mid;

    while (left<=right)
    {
        mid = left + (right-left)/2;
        // we will check which part of the array is sorted and then check if the target is present in that part or not
        if (nums[mid] == target)   
            {
                return mid;
            }
        if (nums[left]==target)
            {
                return left;
            }
        if (nums[right]==target)
            {
                return right;
            }
        
        if (nums[left]<nums[mid])         // we can simply apply binary search in thar part which is sorted
        {
            if (target>nums[left] && target<nums[mid]) // check if target lies in that part or not
                {
                    right = mid-1;
                }
            else
                {
                    left = mid+1;
                }
        }
        else  // if this part is sorted
        {
            if (target>nums[mid] && target<nums[right])
                {
                    left = mid+1;
                }
            else
                {
                    right = mid-1;
                }
        }
    }
        
        return -1;
    }
};