#include<iostream>
using namespace std;

void insertionSort(int* arr, int size) {
    
    for (int idx=0; idx<size-1; idx++) {

        int ptr2 = idx+1;

        if (arr[idx] > arr[ptr2]) {
            swap(arr[idx], arr[ptr2]);
        }

        for (int idx1=idx; idx1>=1; idx1--) {
            if (arr[idx1] < arr[idx1-1]) {
                swap(arr[idx1],arr[idx1-1]);
            }
        }
    }
}

int main() {

    int size;

    cin >> size;

    int * arr = new int[size];

    for (int idx=0; idx<size; idx++) {
        cin >> arr[idx];
    }

    insertionSort(arr,size);

    cout << "Sorted array is"<<endl;

    for (int idx=0; idx<size; idx++) {
       cout << arr[idx] << " ";
    }

    return 0;
}