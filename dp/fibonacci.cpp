//solving this question using memoization 
// I have stopped the recursive calls of same values again and again by storing the already calculated value 

#include <iostream>
using namespace std;

int fib(int num,int* arr){
 
    if (num == 0 || num == 1) return num;
    
    if (arr[num] != 0) return arr[num];
    
    int f1 = fib(num-1,arr);
    int f2 = fib(num-2,arr);
    
    int result = f1 + f2;
    arr[num] = result;
    
    return result;
}

int main(){
    int num;

    cin>>num;

    int arr[num+1];
    
    for (int idx=0; idx<=num; idx++) {
        arr[idx] = 0;
    }
  
    cout<<fib(num,arr)<<endl;

    return 0;
}