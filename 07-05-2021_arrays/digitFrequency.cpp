#include<iostream>
using namespace std;

int digitfreq(int num,int no_tofind)
{  
    int check=0;

    while(num>0)
    {
        int lastdigit = num%10;

        if (lastdigit==no_tofind)               // we will calculate how many times the num is repeated 
        {
            check++;
        }

        num/=10;
    }

    return check;
}

int main()
{
    int num;

    cin>>num;

    int digit;

    cin>>digit;

    cout<<digitfreq(num,digit);

    return 0;
}