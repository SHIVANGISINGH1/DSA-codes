// Input: 5 
// Output: 5*4*3*2*1=120
// here we will take one more parameter which will give the factorial and other will just print nos in decresing order 
// 5 * factorial(4,5*4)
// 4 * factorial(5*4*3)
// 3 * factorial(5*4*3*2)
// 2 * factorial(5*4*3*2*1) return 1 = 120 
// 5*4*3*2*1 =120

#include<iostream>
using namespace std;

string factorial(int num, int fact){
    
    if (num == 1)
    {
        return "1 = " + to_string(fact) ;
    }

    string ans = to_string (num) + "*" + factorial(num-1,fact*(num-1)) ; 

    return ans;    
}
    
int main()
{
    int num; 
    
    cin>>num;

    cout<<factorial(num,num);

    return 0;
}