#include <iostream>
using namespace std;

// function to calculate no of digits
// we will divide the num and count each time to get no of digits

int digits(int num)

{
    int count=0;

    while(num>0)

    {
     count++;
     num/=10;
    }

    return count;
}


int main()
{
    int num;
    cin>>num;
    cout<<digits(num);
}