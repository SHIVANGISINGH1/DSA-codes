#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data,Node* left,Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* construct(int* arr, int lo, int hi) {
    if (lo > hi) {
        return NULL;
    }
    int mid = lo + (hi - lo)/2;

    int data = arr[mid];

    Node* le = construct(arr, lo, mid-1);
    Node* ri = construct(arr, mid+1, hi);

    Node* node = new Node(data , le , ri);
    return node;

}
void displayTree(Node* node) {
    if (node == NULL) {
        return ;
    }

    string str = "";

    str+= node->left == NULL ? "." : to_string(node->left->data);
    str += "<-" + to_string(node->data) + "->";
    str+= node->right == NULL ? "." : to_string(node->right->data);

    cout << str << endl;

    displayTree(node->left);
    displayTree(node->right);

}
int main() {
    int arr[] = {12,25,37,50,62,75,87};

    Node* root = construct(arr,0,6);

    
   
    displayTree(root);
}