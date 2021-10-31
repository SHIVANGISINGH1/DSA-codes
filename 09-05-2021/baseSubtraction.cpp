#include<iostream>
using namespace std;

int getDifference(int base, int num1, int num2)
{
    int lastdigit1,lastdigit2,borrow=0;
    int ans=0,diff;
    int power=1;

    while (num2!=0)
    {
        lastdigit1=num1%10;
        lastdigit2=num2%10;
        diff=lastdigit2-lastdigit1+borrow;
        
        if (diff<0)                           // if our diff is negative means we need to update borrow to -1 and add base to diff
        {
            diff= diff+base;
            borrow=-1;
        }
        else
        { 
            borrow=0;
        }
        ans=diff*power+ ans;
        power*=10;

        num1/=10;
        num2/=10;
    }

    return ans;
}

int main()
{
    int base, num1, num2;

    cin>>base>>num1>>num2;

    cout<<getDifference(base,num1,num2);

    return 0;
}