// here we are doing same cal max without index
// so we will just use no of elments and decrease it 
// we will run the function recursively till n == 1 and return the value at zero index
// and compare the value stored in the val1 (now arr[0]) and return the greater value

#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int noOfEle)
{
    if (noOfEle == 1)
    {
        return arr[noOfEle-1];
    }

    int val1 = max(arr, noOfEle-1);

    if (val1 < arr[noOfEle-1])
    {
        return arr[noOfEle-1];
    }

    return val1;
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

    int ans = max(arr, noOfEle);

    cout << ans << endl;

    return 0;
}