#include<iostream>
using namespace std;
// function to add two arrays

int* addtwoarrays(int size1,int size2,int* arr1,int* arr2)
{   
    
    int max= size1>size2?size1+1:size2+1;                              //  sum array will have size equal to size+1 of larger array
    int limit=max;
    int *ans = new int[max];
    int firstindex= size1-1,secondindex=size2-1,carry=0;               // we will start with the last index of both the arrays 
    
    while(firstindex>=0||secondindex>=0||carry>0)                      // till any num is left or carry is left we will iterate the loop
    {
        int firstno = firstindex>=0?arr1[firstindex]:0;
        int secondno = secondindex>=0?arr2[secondindex]:0;
        int sum = firstno + secondno + carry;                          // we will add the nos with the carry
        
        carry = sum >= 10 ? 1 : 0;                      
        sum = sum % 10;
        
        ans[--max] = sum;                                              // store the sum in ans array and decrement the indexes 
        
        firstindex--;
        secondindex--;
        
    }

    int index=0;

    if(ans[index]==0)                                                  // we will not print any leading zeroes
    {
        index++;
    }

    for ( index; index<limit; index++)
    {
        cout<<ans[index]<<endl;
    }
    
}


int main()
{
    int size1, size2;

    cin>>size1;

    int* arr1 = new int[size1];

    for(int index = 0 ; index < size1; index++)
    {
        cin>>arr1[index];
    }
    
    cin>>size2;

    int* arr2 = new int[size2];

    for(int index = 0 ; index < size2; index++)
    {
        cin>>arr2[index];
    }
    addtwoarrays(size1,size2,arr1,arr2);    
    
    return 0;               
}