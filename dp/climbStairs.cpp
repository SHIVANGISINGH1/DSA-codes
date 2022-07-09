// This is similar to question jump staircase where you have to tell all the possible paths to reach the
// destination, but here you have to tell how many moves you will take to reach the destination.


#include <iostream>
using namespace std;

int cs(int num, int *arr){
    
    arr[0] = 1;
    
    for (int idx=1; idx<=num; idx++) {
        
        int p1 = arr[idx-1];
        int p2 = idx>=2 ? arr[idx-2] : 0;
        int p3 = idx>=3 ? arr[idx-3] : 0;
        
        arr[idx] = p1 + p2 + p3;
    }
   
    return arr[num];
}

int main(){
    int num;

    cin>>num;

    int *arr = new int[num+1];
    
    cout<<cs(num,arr)<<endl;

    return 0;
}