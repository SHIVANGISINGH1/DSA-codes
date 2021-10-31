#include <iostream>
using namespace std;

// function to find the key
int binarysearch(int *arr,int size,int no_to_find)
{  
    int mid;
    int first = 0;
    int last = size - 1;

    while(first<=last)                 // here we are dividing our array at every step to check where our key is 
    {
        mid = first + (last-first)/2;  // we will calculate the midd and compare it with the key
        
        if (no_to_find==arr[mid])
        {
            return mid;
        }
        else if(no_to_find<arr[mid])       // if the key is in upper half we will shift last to mid-1 
        {
            last = mid-1;
        }
        else     // if the key is in right half we will shift first to mid+1
        {
            first = mid+1;
        }
     }
    
    return -1;
}


int main()
{
    int size;

    cin>>size;

    int *arr = new int[size];
    int key;

    for (int index=0; index<size; index++)
    {
        cin>>arr[index];
    }

    cin>>key;
    
    cout<<binarysearch(arr,size,key);
    
    return 0;
}