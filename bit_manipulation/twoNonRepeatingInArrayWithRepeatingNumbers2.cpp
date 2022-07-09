#include<iostream>
using namespace std;

void result(int* arr, int size) {
    
    int Xor = 0;

    // first calculate the xor
    for (int idx=0; idx<size; idx++) {
        Xor = Xor ^ arr[idx];
    }

    // calculate the last set bit
    int count = 0;
    int setBitIdx = 0;

    while(Xor != 0) {

        if (Xor & 1 == 1) {
            setBitIdx = count;
            break;
        }

        Xor = Xor>>1;
        count++;
    }
   
    int Xor1 = 0;
    int Xor2 = 0;
    int mask = 1 << setBitIdx;
    
    // making two seperate grps which will contain the two different inputs
    for (int idx=0; idx<size; idx++) {

        if ((mask & arr[idx]) != 0) {
            Xor1 = Xor1 ^ arr[idx];  
        }
        else {
            Xor2 = Xor2 ^ arr[idx];
        }
    }

    cout << Xor1 << "   " << Xor2;
    
}


int main() {
    
    int arr[] = {1,1,5,2,3,2,3,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    result(arr,size);

    return 0;
}