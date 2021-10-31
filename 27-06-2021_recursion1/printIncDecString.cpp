// input: 5 Output: 5 4 3 2 1 1 2 3 4 5
// 5 + call (4) 
// 4 + call (3)
// 3 + call (2)
// 2 + call (1) -> return 1 1

// 2 + 1 + 1 + 2 -> 
// 3 + 2 + 1 + 1 + 2 + 3 ->
// 4 + 3 + 2 + 1 + 1 + 2 + 3 + 4 ->
// 5 + 4 + 3 + 2 + 1 + 1 + 2 + 3 + 4 + 5 -> return 5 4 3 2 1 1 2 3 4 5 

#include<iostream>
using namespace std;

string printIncDec(int num)
{
    
    if (num == 1)
    {
        return "1 1";
    }

    string ans = to_string(num) + " " + printIncDec(num-1)  + " " + to_string(num);

    return ans;
    
}


int main()
{
    int num;
     
    cin>>num;

    cout<<printIncDec(num);

    return 0;
}