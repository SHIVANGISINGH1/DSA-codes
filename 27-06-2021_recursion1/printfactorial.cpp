// Input: 5 
// output : 120 
// we will call the function for num-1 and multiply num
// factorial (5) = 5 * factorial (4)

#include<iostream>
using namespace std;

int factorial(int num)
{
    if (num == 1)
    {
        return 1;
    }
    
    return num  * factorial(num-1); 
}


int main()
{
    int num; 
    
    cin>>num;

    cout<<factorial(num);

    return 0;
}