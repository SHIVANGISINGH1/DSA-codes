// link : https://leetcode.com/problems/fibonacci-number/

// here we will apply the formula that fib(num) = fib(num-1) + fib(num-2)
// so we are calling the function two times and till we reach 0 or 1 we return 0 or 1 respectively 
// for eg fib(5) = fib(4) + fib(3) =>  fib(4) = fib(3) + fib(2) => fib(3) = fib(2) + fib(1) => fib(2) = fib(1) + fib(0) 
// return 0 for fib(0) and 1 for fib(1) 
// fib(2) = 0 + 1 = 1 return -> fib(3) = 1 + 1 = 2 -> fib(4) = 2 + 1 = 3 -> fib(5) = 3 + 2 = 5 (ans) return 

#include<iostream>
using namespace std;

int main()
{
    class Solution {
    public:
        int fib(int num) 
        {
            if(num==0)
            {
                return 0;
            }

            if(num==1)
            {
                return 1;
            }

            int ans = fib(num-1) + fib(num-2);
                
            return ans;
        }
    };

    return 0;
}