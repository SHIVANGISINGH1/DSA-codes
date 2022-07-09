#include<iostream>
using namespace std;

int findPos(int* arr,int left, int right, int target) {

    while(left <= right) {

        int mid = left + (right-left)/2;

        if (arr[mid] == target) {
            return mid;
        }

        else if (arr[mid] > target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;

}

void shiftArr(int* arr, int pos, int lastPos) {

    for (int idx=lastPos; idx>=1; idx--) {
        if (arr[idx] < arr[idx-1]) {
            swap(arr[idx], arr[idx-1]);
        }
    }
}


void binaryInsertionSort(int* arr,int size) {

    for (int idx=1; idx<size; idx++) {

        int pos = findPos(arr,0,idx-1,arr[idx]);

        if (arr[pos] > arr[idx]) {
            // swap shift
            shiftArr(arr,pos,idx);
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

    binaryInsertionSort(arr,size);

    cout << "Sorted array is"<<endl;

    for (int idx=0; idx<size; idx++) {
       cout << arr[idx] << " ";
    }

    return 0;
}