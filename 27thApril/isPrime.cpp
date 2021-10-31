#include <iostream>
using namespace std;

int main()
{
    int count;
    int num,index,index1;

    // input for how many numbers you have to check
    cin>>count;
    
    // we will take all the numbers

    for (index=0; index<count; index++)
    {    
        cin>>num;

        int flag=1; 
        // check for prime

        for (index=2; index*index<num; index++)
        {
            if (num % index == 0 )
            {
                flag = 0;
                break;
            }
        // print prime if flag is 1   
            if (flag ==1)
            {
                cout<<"prime";
            }
            else
            {
                cout<<"not prime";
            }
        }
    }

    return 0;      
}