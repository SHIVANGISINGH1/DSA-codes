// here we are displaying the array but without use of the index so we will use no of elements and decrease them by 1 and increase
// the arr by 1 
// we will run it till no of elements become zero and on each step we will display the value 

#include<iostream>
using namespace std;

void display(int arr[], int numOfEle)
{
    
    if (numOfEle == 0)
    {
        return ;
    }

    cout<< (*arr) <<endl; // printing the value 

    display(arr+1, numOfEle-1);

    return ;
}


int main()
{
    int numOfEle;

    cin >> numOfEle;

    int arr[numOfEle];

    for (int index =0; index < numOfEle; index++)
    {
        cin >> arr[index];
    }

    display(arr, numOfEle);

    return 0;
}