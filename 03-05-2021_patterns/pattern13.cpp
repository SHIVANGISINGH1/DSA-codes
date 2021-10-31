#include<iostream>
using namespace std;
// Pascals Triangle

int main()
{
    int lines;

    cin >> lines;           //lines= no of lines

    for(int line = 0 ; line < lines ; line++)       //row ctr
    {
        int t = 1;                                  // t is num to print 

        for(int ele = 0 ; ele <= line ; ele++)     //ele=element   
        {
            cout<<t<<'\t';

            t=t*(line-ele)/(ele+1);               // formula [(K+1)th term = Kth term * (n-r)/r+1]
        }

        cout<<'\t';

    }
    
    return 0;

}
// pattern 13
//  1
//  1   1
//  1   2   1
//  1   3   3   1
//  1   4   6   4   1