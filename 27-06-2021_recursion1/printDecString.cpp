//Input: 5 output:5 4 3 2 1
// 5 + call (4) 
// 4 + call (3)
// 3 + call (2)
// 2 + call (1) -> return 1 

// 2 + 1 -> 3 + 2 + 1 -> 4 + 3 + 2 + 1 -> 5 + 4 + 3 + 2 + 1 -> return to main  

#include<iostream>
using namespace std;

string Decreasing (int num)
{  
    if (num==1)
    {
        return to_string(1); 
    }

    return to_string(num) + " " + Decreasing(num-1); 
   
}

int main() 
{
    int num ;

    cin >> num ;

    cout << Decreasing (num) ;

    return 0;
}