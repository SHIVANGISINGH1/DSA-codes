// Input-> 5
// Ouput-> 5 4 3 2 1
// first we will print from n and then call the function for num-1 and print again 
// 5 (p) call -> 4(p) call -> 3(p) call -> 2(p) call -> 1(p) -> call 0 return 

#include<iostream>
using namespace std;

void printDecreasing(int num)
{
    if (num == 0)
    {
        return ;
    } 

    cout<<num<<endl; // printing the nos from end

    printDecreasing(num-1); // calling the function 

    return ;
}

int main()
{
    int num;

    cin >> num;

    printDecreasing(num);

    return 0;
}