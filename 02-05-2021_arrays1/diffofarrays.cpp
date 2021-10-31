#include<iostream>
using namespace std;

// function to subtract two arrays
void diff_arrays(int size1,int size2,int* arr1,int* arr2)
{
   int max= size2<size1?size1:size2;                              // size of diff array will be same as size of larger array
   int range = max;
   int *ans = new int[max];
   int firstidx = size1-1, secondidx = size2-1;             
   int borrow =0;
   int diff;
   
   while (firstidx>=0||secondidx>=0)                 // we will iterate till any one index is left 
    {  
       int last1= firstidx>=0?arr1[firstidx]:0;
       int last2= secondidx>=0?arr2[secondidx]:0;
       
       last2 = last2-borrow;                        // the last2 will be last2-borrow
       
       if(last1<=last2)
        {
            diff = last2-last1;                    // if last1 is smaller or equal to last2 no need to borrow
            borrow=0; 
        }
       if (last2<last1)
        { 
           diff = last2 +10 - last1 ;            // we will add 10 in last2 if its smaller then last1 and we will borrow one
           borrow = 1;
        }
  
       ans[--max] = diff;                        // storing the values in ans array
       
       firstidx--;
       secondidx--;
    }

    int index=0;

    while(index<range)
    {
        if (ans[index]==0)                       // to remove leading zeroes
        {
            index++;
        }
        else
        {
            break;
        }
    }

    for (index; index<range; index++)
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
    
    diff_arrays(size1,size2,arr1,arr2);
    
    return 0;
}