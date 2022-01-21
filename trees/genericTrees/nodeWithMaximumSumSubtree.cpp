#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int c = INT_MAX;
int flloor = INT_MIN;

struct Node {
  int data;
  vector<Node*>children;
};

Node* newNode(int key) {
  Node* temp = new Node;
  temp->data = key;
  return temp;

}

Node* construct(int arr[], int n ) {
  Node* root = NULL;
  stack<Node*>st;
  for (int i = 0; i < n; i++) {
    if (arr[i] == -1) {
      st.pop();
    } else {
      Node* t = newNode(arr[i]);

      if (st.size() > 0) {
        st.top()->children.push_back(t);
      } else {
        root = t;
      }
      st.push(t);
    }
  }
  return root;
}



void cnf(Node* node, int data) {
  if (node->data > data)
  {
    if (node->data < c)
    {
      c = node->data;
    }
  }

  if (node->data < data)
  {
    if (node->data > flloor)
    {
      flloor = node->data;
    }
  }

  for (Node* child : node->children)
  {
    cnf(child, data);
  }

}

int kthlarge(Node* node, int k)
{
    int data = INT_MAX;
    
    while(k--) {
        cnf(node,data);
        data = flloor;
        flloor = INT_MIN;
    }
    return data;
}

Node* maxNodeSum = NULL;
int maxS = INT_MIN;

int maxSum(Node* node) {
    int sum = 0;
    
    
    for (int idx=0; idx<node->children.size(); idx++) {
        int sumVal = maxSum(node->children[idx]);
        sum += sumVal;
        
    }
    
    sum += node->data;
    if (sum > maxS) {
            maxS = sum;
            maxNodeSum = node;
        }
    return sum;
    
}
int main() {

  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Node* root = construct(arr, n);
  
  maxSum(root);
  cout << maxNodeSum->data << "@" << maxS;
}