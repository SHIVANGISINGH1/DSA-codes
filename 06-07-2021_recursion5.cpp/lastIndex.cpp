// here we have to calculate the last index 
// so we will call the function idx + 1 recursively and we will check in post here
// when index is equal to the no of elements it will return -1 to the function 
// if our store has -1 value we will check if our element is equal to data if yes return its index else return -1
// if store is not -1 like in next case when we found our element already we will return the already stored value 

#include<iostream>
using namespace std;

int firstIndex(int arr[], int idx, int key, int noOfEle)
{
    if(idx == noOfEle) 
    {
        return -1;
    }

    int store = firstIndex(arr, idx+1, key, noOfEle);

    if (store == -1)
    {
        if (arr[idx] == key)
        {
            return idx;
        }
        else
        {
            return -1;
        }
    }

    else
    {
        return store;
    }
   
    return -1;
   
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