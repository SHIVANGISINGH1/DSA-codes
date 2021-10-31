#include<iostream>
using namespace std;

int main()
{
    int size;

    cin>>size;
    
    int* arr = new int[size];
    
    for(int index= 0 ; index<size ; index++)
    {
        cin>>arr[index];
    }
    
    int counter=0;
    int index=0;

    while(counter<size)   // this outer loop will run size times
    {       
        for (index=counter; index<size; index++)   // it will start from counter 
        {
            for (int index1=counter; index1<=index; index1++)  // this will print the pattern 
            {
                cout<<arr[index1]<<'\t';
            }

        cout<<endl;
        }

        counter++;
    }

    return 0;
}