#include <iostream>
using namespace std;

int main() 
{
	long int num;
    
	cin>>num;

	for (int value=1; value*value<=num; value++)    // we will print perfect squares till that num
	{
	    cout<<(value*value)<<endl;
	}

	return 0;
}