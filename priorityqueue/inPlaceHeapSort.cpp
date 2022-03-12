#include<bits/stdc++.h>
using namespace std;

void insert(int *arr , int size) {
    int len = 1;
    
    while(len <= size) {
        int childIdx = len - 1;
// down-heapify
        while(childIdx > 0) {
            int parentIdx = (childIdx - 1)/2;

            if (arr[parentIdx] > arr[childIdx]) {
                int temp = arr[parentIdx];
                arr[parentIdx] = arr[childIdx];
                arr[childIdx]= temp;
            }
            else {
                break;
            }
            childIdx = parentIdx;
        }

        len++;
    }    

}


void heapSort(int *arr, int size) {

    int len = size - 1;
    while(len >= 0) {

        int ans = arr[0];
        arr[0] = arr[len];
        arr[len] = ans;

        int parentIdx = 0;
        int leftChildIdx = 2*parentIdx + 1;   
        int rightChildIdx = 2*parentIdx + 2;   
        
        while(leftChildIdx < len) {
// up-heapify
            int minIdx = parentIdx;

            if (arr[minIdx] > arr[leftChildIdx]) {
                minIdx = leftChildIdx;
            }

            if (rightChildIdx < len && arr[minIdx] > arr[rightChildIdx]) {
                minIdx = rightChildIdx;
            }

            if (parentIdx == minIdx) {
                break;
            }

            int temp = arr[parentIdx];
            arr[parentIdx] = arr[minIdx];
            arr[minIdx] = temp;

            parentIdx = minIdx;

            leftChildIdx = 2*parentIdx + 1;   
            rightChildIdx = 2*parentIdx + 2;   
        }

        len--;
    }
    
}


int main() {

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int len = sizeof(arr) / sizeof(arr[0]);

    insert(arr,len);
    heapSort(arr,len);

    for (int idx=0; idx<len; idx++) {
        cout << arr[idx] << " ";
    }
}