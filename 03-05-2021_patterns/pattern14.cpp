#include<iostream>
using namespace std;

int main()
{
    int num ;

    cin >>num;
    
    for(int row=1; row<=10; row++)           // we have to print table
    {
        cout<<num<<" "<<"*"<<" "<<row<<" "<<"="<<" "<<num*row;
        cout<<endl;
    }
    
    return 0;
}
// pattern 14
// 3*1 = 3
// 3*2 = 6
// ...