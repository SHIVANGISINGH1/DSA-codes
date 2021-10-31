#include<iostream>
using namespace std;

int main()
{
    int size;

    cin>>size;

    int* arr = new int[size];

    for(int index = 0 ; index < size; index++)
    {
        cin>>arr[index];
    }

    int data;

    cin>>data;

    int left = 0;
    int right = size-1;
    int ciel=-1 ,floor=-1;

    if (size == 1)        // if there is only one element 
    {
        ciel =arr[0];
    }

    while(left<=right)
    {

        int mid = left + (right-left)/2;

        if (arr[mid]==data)
        {
            cout<<arr[mid];
        }

        else if (mid == size-1)       // if mid is the last element 
        {
            floor = arr[mid];
            break;
        }

        else if (arr[mid]<data && arr[mid+1]>data)  // we will check if mid ele is smaller then data and mid+1 ele is greater 
        {                                          // this will give ciel and floor 
            ciel = arr[mid+1];
            floor = arr[mid];
            break;
        }

        else if (arr[mid]<data)  // apply simply binary search
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }

    }

    cout<<ciel<<endl<<floor;

    return 0;
}