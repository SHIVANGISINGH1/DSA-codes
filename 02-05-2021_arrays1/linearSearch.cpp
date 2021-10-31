#include<iostream>
using namespace std;

// function to find the key 
int findkey(int *arr,int size,int no_to_find)
{
    for (int index=0;index<size; index++)
    {
        if (arr[index]==no_to_find)  // if we find our key we will return the index or -1
        {
            return index;
        }
    }
    
    return -1;
}

int main()
{
    
    int size;

    cin>>size;

    int *arr = new int[size];

    for (int index=0; index<size; index++)
    {
        cin>>arr[index];
    }

    int key;

    cin>>key;

    cout<< findkey(arr,size,key);

    return 0;
}