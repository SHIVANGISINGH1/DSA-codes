// here we have to display the array so we will call the function recursively for index + 1 to go to next indexes
// and print the value at each index

#include<iostream>
using namespace std;

void display(int arr[], int idx, int numOfEle)
{
    if (idx == numOfEle)
    {
        return ;
    }

    cout<<arr[idx]<<endl;

    display(arr, idx+1, numOfEle);

    return ;
}


int main()
{
    int numOfEle;

    cin >> numOfEle;

    int arr[numOfEle];

    for (int index = 0; index < numOfEle; index++)
    {
        cin >> arr[index];
    }

    display(arr, 0, numOfEle);

    return 0;
}