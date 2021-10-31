#include<iostream>
using namespace std;

int main()
{
int num,base;

cin>>num>>base;

int ans=0;
int power=1;

while(num!=0)
{
    int lastdigit = num % base;   
                                // we will divide the num by base and print the converted num 
    ans += lastdigit * power;
    power*= 10;

    num/= base;
}

cout<<ans;

return 0;
}