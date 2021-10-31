#include<iostream>
using namespace std;

int main()
{
    int num,base;

    cin>>num>>base;

    int power=1;
    int ans=0;

    while(num!=0)
    {
        int lastdigit=num%10;

        ans += lastdigit*power;     // multiply power with remainder and add in the ans 
        power*=base;               // we will update the power
        
        num/=10;
    }

    cout<<ans;

    return 0;
}