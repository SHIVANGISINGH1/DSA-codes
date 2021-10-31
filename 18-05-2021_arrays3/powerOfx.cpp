class Solution
{
public:
    double myPow(double x, int power)  // here x is the num whose power is calculated
    {   
        long temppow=power;

        if (temppow<0)
        {
            temppow = -temppow;
        }

        double ans=1.0;
    // if power is odd we will multiply x with ans and dec the power 
    // if even multiply x with x and divide power with 2
        while(temppow!=0) 
        {
            if (temppow%2==1)
            {
                ans*=x;
                temppow--;
            }
            else
            {
                x*=x;
                temppow/=2;
            }
        }
        
        if (power<0)
        {
            return 1.0/ans;
        }
        else
        {
             return ans;
        }
    }
};