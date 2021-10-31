// here we have to find the first index of the given element 
// so we are just calling the function for index + 1 and checking if it is equal to the data if yes then return the index
// if it is false it goes to next iteration till the last element if not found then return -1

#include<iostream>
using namespace std;

int firstIndex(int arr[], int idx, int key, int noOfEle)
{
    if (idx == noOfEle) 
    {
        return -1;
    }

    if (arr[idx] == key) 
    {
        return idx;
    }

    int store = firstIndex(arr, idx+1, key, noOfEle);

    return store;
}


int main()
{
    int noOfEle;

    cin >> noOfEle;

    int data;

    int arr[noOfEle];

    for (int index = 0; index < noOfEle; index++)
    {
        cin >> arr[index];
    }

    cin >> data;

    int ans = firstIndex(arr, 0, data, noOfEle);

    cout << ans << endl;

    return 0;
}