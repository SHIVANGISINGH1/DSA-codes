// print zig zag is for num = 2 pattern is 2 1 1 1 2 1 1 1 2 and for num = 1 pattern is 1 1 1
// so we can see that for printing tha pattern for 2 we have 2 num(1) 2 num(1) 2
// so we will print the num then call for num-1 then print and call for num-1 and print again 
// the base case is simple for num=0 we will return 
// here we are calling the function twice and printing the num in pre , in and post of function call

#include<iostream>
using namespace std;
// if num = 2
void printZigZag(int num)
{
    
    if(num == 0)
    {
        return ;
    }
    
    cout<<num<<" ";    // PRE print->2 print->1 print->1
    
    printZigZag(num-1); // calling the function pzz(1) -> pzz(0) <- return pzz(0) <- return
    
    cout<<num<<" ";   // IN print->1 print->2 print->1
    
    printZigZag(num-1); // calling the function pzz(0) <- return pzz(1)  pzz(0) <- return
    
    cout<<num<<" ";   // POST print->1 print->1 print->2
    
    return ;
}



int main()
{
    int num;

    cin>>num;

    printZigZag(num); // 2 1 1 1 2 1 1 1 2

    return 0;
}