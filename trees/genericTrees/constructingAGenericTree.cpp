#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    vector<Node*> children;

    Node() {
        this->data = data;
    }

    ~Node() {
        int size = children.size();

        for (int idx=0; idx<size; idx++) {
            delete children[idx];
        }
    }

    Node *takeInput() {
        int size;
        
        cin >> size;

        int *arr = new int[size];

        for (int idx=0; idx<size; idx++) {
            cin >> arr[idx];
        }
        Node* root = NULL;
        stack<Node*> st;

        for (int idx=0; idx<size; idx++) {
            if (st.size() > 0) {

            }
            else {
                root = 
            }
        }
    }
};

int main () {
}