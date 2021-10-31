// here we have to display the array in reverse order so we will first call the function recursively for index + 1
// then on hiting the base codtion after return we will print the array (POST) 

#include<iostream>
using namespace std;

void display(int arr[], int idx, int noOfEle)
{
    if (idx == noOfEle)
    {
        return ;
    }

    display(arr, idx+1, noOfEle);

    cout<<arr[idx]<<" "; // printing the value in post 

    return ;
}


int main()
{
    int noOfEle;

    cin >> noOfEle;

    int arr[noOfEle];

    for (int index = 0; index < noOfEle; index++)
    {
        cin >> arr[index];
    }

    display(arr, 0, noOfEle);

    return 0;
}