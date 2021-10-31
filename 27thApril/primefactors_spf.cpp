#include<iostream>
using namespace std;

// function to find smallest prime factor

void primefactors(int num)
{
    int spf[num+1] = {0};
    int index;

    // initialize every value of spf array with its index 

    for (index=2; index<=num; index++)
    {
        spf[index] = index;
    }
    // marking the values with thier smallest prime factor

    for (index=2; index*index<=num; index++)
    {
        if (spf[index]==index)
        {
            for (int index2=index*index; index2<=num; index2+=index)
            {
                if (spf[index2]==index2)
                {
                    spf[index2]=index;
                }
            }
        }
    }
    // to print the prime factors
        
    while(num!=1)
    { 
        cout<<spf[num]<<'\t';
        num= num/spf[num];
    }
    
}


int main()
{
   int num;

   cin>>num;

   primefactors(num);

   return 0;
}