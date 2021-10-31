#include <iostream>
using namespace std;

int ternarySearch(int size,int *arr,int key)
{
    int left  = 0;
	int right =size-1;
	
	while(left<=right)
	{
        int mid1= left+(right-left)/3;                                       // we will calculate two mid pts
	    int mid2= right-(right-left)/3;

	    if (arr[mid1]==key)
		{
	    	return mid1;
		}
	    else if(arr[mid2]==key)
	    {
			return mid2;
		}
	    else if(key<arr[mid1])                    // if key is smaller then arr[mid1] it will lie in the left region
	    {
			right=mid1-1;
		}
	    else if(key>arr[mid2])                     // if key is greater then arr[mid2] it will lie in the right region
	    {
			left=mid2+1;
		}

	    else                                     // it can also lie between mid1 and mid2
	    {
	        left=mid1+1;
	        right=mid2-1;
        }
	}
	
	return -1;
	
}
int main() 
{
	int size;

	cin>>size;

	int key;
	int *arr = new int[size];

	for (int index=0; index<size; index++)
	{
	    cin>>arr[index];
	}
	cin>>key;

    cout<<ternarySearch(size,arr,key);
    
	return 0;
}