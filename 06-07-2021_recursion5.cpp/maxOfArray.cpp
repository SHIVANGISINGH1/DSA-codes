// here we are printing the maximum value of array 
// we are calling the function recursively iterating to next index and checking if the value stored in the function call is
// greater then the value at that arr[index]
// if yes we return the arr[index]

#include <iostream>
using namespace std;

int max(int arr[], int idx, int noOfEle)
{
    if (idx == noOfEle)
    {
        return -1;
    }

    int store= max(arr, idx+1, noOfEle);

    if (arr[idx] > store)
    {
        return arr[idx];
    }

    return store;
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

    int ans = max(arr, 0, noOfEle);

    cout << ans << endl;

    return 0;
}