#include<bits/stdc++.h>
using namespace std;

class priorityQueue {
    public:
    vector<int> pq;

    bool isEmpty() {
        if (pq.size() == 0) return true;
        return false;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (isEmpty() == true) {
            return 0;
        }
        return pq[0];
    }

    void insert(int val) {

        pq.push_back(val);

        int childIdx = pq.size() - 1;
        

        while (childIdx > 0) {
            int parentIdx = (childIdx - 1)/2;
                
            if (pq[parentIdx] > pq[childIdx]) {
                int temp = pq[parentIdx];
                pq[parentIdx] = pq[childIdx];
                pq[childIdx] = temp;
            }
            else {
                break;
            }
            childIdx = parentIdx;
        
        }
        
    }

    int remove () {
        if (isEmpty() == true) {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq[pq.size() - 1] = ans;

        pq.pop_back();

        int parentIdx = 0;
        int leftChildIdx =  (2*parentIdx) + 1;
        int rightChildIdx = (2*parentIdx) + 2;


        while (leftChildIdx < pq.size()) {
            
            int minIdx = parentIdx;

            if (pq[minIdx] > pq[leftChildIdx]) {
                minIdx = leftChildIdx;
            }
            if (rightChildIdx < pq.size() && pq[minIdx] > pq[rightChildIdx]) {
                minIdx = rightChildIdx;
            }
            
            if (parentIdx == minIdx) break;
            int temp = pq[minIdx];
            pq[minIdx] = pq[parentIdx];
            pq[parentIdx] = temp;

            parentIdx = minIdx;
            leftChildIdx = (2*parentIdx) + 1;
            rightChildIdx = (2*parentIdx) + 2;
        }
        return ans;
    }

};