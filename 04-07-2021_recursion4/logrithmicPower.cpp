// link : https://leetcode.com/problems/powx-n/
// Here we will calculate power with the idea that 2^4 = 2^2 * 2^2 and 2^5 = 2^2 * 2^2 * 2 
// so for odd powers we will multiply it with num 
// for eg power(2,5) => mul = power(2,2) => mul = power(2,1) => mul = power(2,0) <=return 1
// now we will multiply mul * mul and if our power is odd we will multiply num with it and return 

    class Solution {
    public:
        double myPow(double num, int temppower) 
        {
            double power = temppower;
            
            if (power<0)
            {
                power = -power;
            }
            
            double ans ;
                
            if (power == 0)
            {
                return 1.0;
            }

            double mul = myPow(num,power/2);
            
            if ((long int)power % 2==0) // checking if power is even or odd
            {
                ans = mul*mul;
            }
            else
            {
                ans = mul *mul *num;
            }
            if (temppower<0)
            {
                return 1.0/ans;
            }
            else
            {
                return ans;
            }

            return 0.0;
        }
};