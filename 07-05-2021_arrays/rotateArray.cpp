#include<iostream>
using namespace std;

void revarr(int *arr,int index1,int index2)              // to reverse the array between any two index
{ 
    int left=index1;
    int right=index2;

    while(left<right)                          
    {
        int temp=arr[left];

        arr[left]=arr[right];
        arr[right]=temp;

        left++;
        right--;
    }
    
}
void rotate(int* arr, int size, int noOfTimes)
{
    noOfTimes = noOfTimes%size;

    if(noOfTimes<0)
    {
        noOfTimes = size+noOfTimes;  // we will divide the array in two parts reverse them and then we will reverse the complete array to get the
    }
                                // rotated array
     //  first we will reverse the part from index=size-noOfTimes(noOfTimes+1) to last ele
    //  second we will reverse the left part from index 0 to size- noOfTimes-1(noOfTimes)  
    // then we will reverse the complete array and get the rotated array
    revarr(arr,size-noOfTimes,size-1); 
    revarr(arr,0,size-noOfTimes-1);  
    revarr(arr,0,size-1);  
}

void display(int* arr, int size)
{
    for(int index = 0 ; index < size; index++)        // print the rotated array
    {
        cout<<arr[index]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size, r;                                 // r is the num of times we have to rotate the array
   
    cin>>size;

    int* arr = new int[size];

    for(int index = 0 ; index < size; index++)
    {
        cin>>arr[index];
    }
    
    cin>>r;
    
    rotate(arr,size,r);
    display(arr,size);

    return 0;
}