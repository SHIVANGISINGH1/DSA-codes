// here we are doing the same printing the array in reverse but without index 
// so we are just calling the function for no of elements - 1 and printing the value (IN PRE)

#include<iostream>
using namespace std;

void display(int arr[], int noOfEle)
{
    if (noOfEle == 0)
    {
        return ;
    }

    cout<< arr[noOfEle-1]<< endl; // printing the value from last

    display (arr, noOfEle-1); 

    return ;
}

int main()
{
    int noOfEle;

    cin >> noOfEle;

    int arr[noOfEle];

    for (int index = 0; index < noOfEle; index++)
    {
        cin >> arr[index];
    }

    display(arr, noOfEle);

    return 0;
}