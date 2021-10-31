class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
{
    int left=0;
    int right=nums.size()-1;

    while(left<=right)
    {
        int mid=left+(right-left)/2;
        
        if (nums[mid]==target|| nums[left]==target|| nums[right]==target)  
        {
            return true;
        }
        // checking if our left right and mid ele are same or not if they are same we will inc the left and dec right 
        if(nums[mid]==nums[left] &&nums[mid]==nums[right])
        {
            left++;
            right--;
        }
        // checking which part is sorted and then finding the target same as rotated sorted 1
        else  if(nums[mid]<nums[left])
        {
            if(target<=nums[right]&&target>nums[mid])
                {
                    left=mid+1;
                }
            else
                {
                    right=mid-1;
                }
        }

        else 
        {   
            if(target>=nums[left] && target<nums[mid])
                {
                    right=mid-1;
                }
            else
                {
                    left=mid+1;
                }
        }
    }
    
         return false;
    }
     
};