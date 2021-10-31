#include<iostream>
using namespace std;

void inverse(int* arr, int size)
{
    int *temp= new int[size];   // making another array temp for inverse

    for (int index=0; index<size; index++)
    {   
        int value;

        value = arr[index]; 
        temp[value]=index;  // at value(index) adding the value of index 
    
    }

    for(int index = 0 ; index < size; index++) // display the inverse arrray
    {
        cout<<temp[index]<<endl;
    }
}


int main()
{
    int size;

    cin>>size;

    int* arr = new int[size];
    
    for(int index = 0 ; index < size; index++)
    {
        cin>>arr[index];
    }
    
    inverse(arr,size); // calling the function

    return 0;
}