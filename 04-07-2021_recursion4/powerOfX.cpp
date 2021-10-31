// we know 2^5 = 2 * 2^4 and 2^4 = 2 * 2^3
// so we will use this in our code powerFunc(2,5) => 2 * powerFunc(2,4) => 2 * powerFunc(2,3) => ..at end we return 1 when power = 0 
// finally we return our ans 
// complexity 0(n) where n = power 

#include<iostream>
using namespace std;

int powerFunc(int num,int power)
{
    if (power == 0)
    {
        return 1;
    }
   
    int ans = num * powerFunc(num,power-1);
    
    return ans;
}


int main()
{
    int power,num; 
    
    cin>>num>>power;

    cout<<powerFunc(num,power);

    return 0;
}
