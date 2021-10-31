#include<iostream>
using namespace std;

// function to print numbers

void primesieve(int num)
{  
	int index;
	int array[num+1]= {0};

	// making all values of the array as true(0)

	for(index=0; index<=num; index++)
	{
		array[index] = 0;
	}

		// checking the number is prime or not 
		//we will check till root of that number 

	for(index=2; index*index<=num; index++)
	{
							 
		// for the given index we will mark all the multiples greator than or equal to square as false(1)
		//those marked value are all not prime
		//we will not check for already marked values of index

		if (array[index] == 0)
		{
			for(int mul=index*index; mul<=num; mul+=index)
			{
				array[mul] = 1;
			}
		}

	}
		//print all true values of index (prime num)

	for(index = 2; index<=num; index++)
	{

		if (array[index]== 0)
		{
			cout<<index<<" ";
		}
						
	}

}  
	
int main()
{
	int num;

	cin>>num;

	primesieve(num);

	return 0;
}