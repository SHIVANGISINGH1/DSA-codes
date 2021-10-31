// Input: 5
// Output:1 2 3 4 5
// here first we will call the function for num-1 till we get 0 and return and print the num
// 5 -> call 4 -> call 3 -> call 2 -> call 1 -> call 0 return and print
// print 1 2 3 4 5

#include<iostream>
using namespace std;

void printIncreasing(int num)
{
    if (num == 0)
    {
        return ;
    }

    printIncreasing(num-1); // calling for num-1

    cout<<num<<"\n";  // printing the nos from starting

    return ;
}


int main()
{
    int num; 

    cin>>num;

    printIncreasing(num);

    return 0;
}