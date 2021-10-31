#include <iostream>
#include<math.h>
using namespace std;

// function to calculate no of digits

int digits(int num)

{
    int count=0;
    while(num>0)

    {   count++;
        num/=10;
    }

    return count;
}


int main()
{
    int num;
    cin >>num;
    
    int total_count=digits(num);

    // to print the digits we will divide the num with 10 power no of digits -1
    while(total_count>0)

    {   int divisor=pow(10,--total_count);
        int digit=num/divisor;
        num = num % divisor;
        cout <<digit<<endl;
    }
    
}