#include <iostream>
using namespace std;

int main()
{
    int num;

    cin >>num;
    
    int first,second,third;

    first=0; second=1;
    cout<<first<<endl<<second<<endl;
                          
    while(num-2>0)
    {                           // the third num is the sum of first and second num
        third = first+second;
        cout<<third<<endl;  
        first = second;
        second = third;  
        num--;
    }

    return 0;    
}