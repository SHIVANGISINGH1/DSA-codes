// Input-> 5
// Ouput-> 5 4 3 2 1 1 2 3 4 5

// first we will print from num and then call the function for num-1 and print again 
// 5 (p) call -> 4(p) call -> 3(p) call -> 2(p) call -> 1(p) -> call 0 return and print again 

// print 1 2 3 4 5

#include<iostream>
using namespace std;

void printIncDec(int num)
{
    if (num == 0)
    {
        return ;
    } 

    cout<<num<<"\n"; // print the num from end

    printIncDec(num-1); // call the function for num-1

    cout<<num<<"\n"; // print the num from start

    return ;
}


int main()
{
    int num; 

    cin>>num;

    printIncDec(num);

    return 0;
}