#include<iostream>
using namespace std;

int main()
{
    int num,base1,base2;

    cin>>num>>base1>>base2;

    int mul=1;
    int ans=0;
    int power=1;
    int finalans=0;
    
    // converting the number given into decimal base
    if (base1!=10)
    {   
        while(num!=0)
        {
            int lastdigit = num%10;

            ans = lastdigit*mul + ans;
            mul*=base1;

            num/=10;
        }
    }
    // converting the ans in base2 given in the q
        while(ans!=0)
        {
            int lastdigit= ans%base2;

            finalans = lastdigit*power + finalans;
            power*=10;
            
            ans/=base2;
        }


    cout<<finalans;
    
    return 0;
}