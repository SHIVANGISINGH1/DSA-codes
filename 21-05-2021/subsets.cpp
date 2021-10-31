#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int size;

    cin>>size;
    
    int *arr = new int[size];
    
    for (int index=0; index<size; index++)
    {
        cin>>arr[index];
    }

    int totalsize = 1<<size;                 // totalsize will be equal to the total number of subsets 
    
    for (int cur=0; cur<totalsize; cur++)   // this loop from 0 to totalsize-1 is used to iterate all the subsets and print the req pattern 
    {
        int temp = cur;       
        int output[size];
        
        for (int index=size-1; index>=0; index--)   // we are dividing the num and converting into binary so we will run the loop from size-1
        {   
            // converting in binary - checking
        
            bool print = temp&1;                 // we will check if our number is even (remainder is 0 or one)
            
            temp/=2;                            
            if (print)                         // if we get 1 as print we will store arr[index] it in our output array at that index only 
            {
                output[index]= arr[index];
            }
            else
            {
                output[index] = -1;    // else we will store -1 in it  
            }            
        }
    
    
    
    for (int index=0; index<size; index++)
    {   
        if (output[index]==-1)         // print dash if we get -1 means zero was remainder
        {
            cout<<"-"<<'\t';
        }          
        else
        {
            cout<<output[index]<<'\t';  // else print that ele
        }    
    }
    
    cout<<endl;
    }

    return 0;
}