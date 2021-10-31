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
    
    int first=0;
    int last = size-1;
    int fi = -1;                // fi is first index temp variable to store the first index

    while (first<=last)
    {
       int mid = first + (last-first)/2;

       if (data<arr[mid])
        {
            last = mid-1;
        }
        else if (data>arr[mid])
        {
            first = mid+1;
        }
        else    // we will simply apply binary search but for first index we will search in the left part if arr[mid]equal to target
        { 
            fi = mid;
            last = mid-1;
        }
    }
        cout<<fi<<endl;   
    
    first=0;
    last = size-1;

    int li = -1;   // li is last index temp variable to store the last index

    while (first<=last)
    {
        int mid = first + (last-first)/2;

        if (data<arr[mid])
        {
            last = mid-1;
        }
        else if (data>arr[mid])
        {
            first = mid+1;
        }
        else
        {
            li = mid;    // we will simply apply binary search but for last index we will search in the right part if arr[mid]equal to target
            first = mid+1;
        }
    }
        cout<<li;  

    return 0;
}