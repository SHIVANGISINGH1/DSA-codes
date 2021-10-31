#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;

    cin>>num;

    int ans=0;
    int index = 1;

    //  The lastdigit is calculated, using lastdigit and index we find our inverse

    while(num>0)
    
    {
        int lastdigit = num%10;

        // inverse is the product of index and the lastdigit reduced by one
        ans = ans + index*pow(10,lastdigit-1);
        index++;
        num/=10;
        
    }

    cout<<ans;

    return 0;   
}