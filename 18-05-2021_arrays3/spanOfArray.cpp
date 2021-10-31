#include<iostream>
using namespace std;

int main()
{
    int size;

    cin>>size;
    
    int *arr = new int[size];
    
    for(int index=0; index<size; index++)
    {
        cin>>arr[index];
    }
    
    int max = arr[0]; // initiallize max min 
    int min = arr[0];
    
    for (int index=1; index<size; index++)
    {
        if (arr[index]>max)   // calculate max by comparing
        {
            max = arr[index];
        }
    
        if (arr[index]<min)  // calculate min by comparing
        {
            min = arr[index];
        }
    }

    int span=max-min;

    cout<<span;

    return 0;
}