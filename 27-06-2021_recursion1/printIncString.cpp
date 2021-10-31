// call (5)
// call (4) 
// call (3)
// call (2)
// call (1) -> return 1  

// 1 + 2 -> 1 + 2 + 3 -> 1 + 2 + 3 + 4 -> 1 + 2 + 3 + 4 + 5 ->  return to main  

#include<iostream>
using namespace std;

string Decreasing (int num)
{  
    if (num == 1)
    {
        return to_string(1); 
    }

    string ans = Decreasing(num-1); // calling the function for num-1

    return ans + to_string(num) ; 
   
}

int main() 
{
    int num ;

    cin >> num ;

    cout << Decreasing (num) ;

    return 0;
}