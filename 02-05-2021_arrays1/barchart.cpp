#include<iostream>
using namespace std;

int main()
{
    
   int size;

   cin>>size;

   int *arr = new int[size];
   int max=-1;                                  // giving max minimum value

   for (int index=0; index<size; index++)
   {
       cin>>arr[index];

       if(arr[index]>max)                     // calculating the maximum value
       {
           max=arr[index];
       }
   }
   
   int mx = max;

   for (int rows = mx; rows>=1; rows--)       // we will print the chart from the maximum value in array it will give no of rows
   {
       for (int index=0; index<size; index++)
       {
           if(arr[index]>=rows)              // we will print stars only when the array[index] is larger or equal to that row 
           {                                 
               cout<<"*"<<"	";
           }
           else
           {
                cout<<'	';
           }
       }
       cout<<endl;
   }
   
   return 0;
}