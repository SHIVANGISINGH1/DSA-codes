#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node

{

public:

  int data = 0;

  vector<Node*> children;



  Node(int data)

  {

    this->data = data;

  }

};

Node* constructor01(vector<int>& arr)

{

  if (arr.size() == 0)

    return NULL;



  vector<Node*> stack;

  stack.push_back(new Node(arr[0]));



  Node* root = stack[0];



  for (int i = 1; i < arr.size(); i++)

  {

    if (arr[i] != -1)

    {

      Node* node = stack.back();

      Node* nnode = new Node(arr[i]);



      node->children.push_back(nnode);

      stack.push_back(nnode);

    }

    else

      stack.pop_back();

  }

  return root;

}

// In this q we will use two stacks parentSt and childSt intially we will add root ele in parent
// then RPA algo and add its children in the child stack but we will take notice of the level 
// cause its output 
// 10 
// 40 30 20 
// 50 60 70 80 90 100 
// 120 110

void levelOderZigZag(Node* node)
{

    stack<Node*> parentSt;
    stack<Node*> childSt;
    int level= 0;
    parentSt.push(node);
    
    while(parentSt.size() > 0 || childSt.size() > 0) {
        Node* n = parentSt.top();
        parentSt.pop();
        cout << n->data << " "; 
        if (level%2 == 0) {
            for (int idx=0; idx<n->children.size(); idx++) {
                childSt.push(n->children[idx]);
            }
        }
        else {
            for (int idx= n->children.size() - 1; idx>=0; idx--) {
                childSt.push(n->children[idx]);
            }
        }
        if (parentSt.size() == 0) {
            cout << endl;
            parentSt = childSt;
            while(childSt.size() > 0) {
                childSt.pop();
            }
            level++;
        }
    }

}

void solve()
{
  int n;
  cin >> n;
  vector<int>arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Node* root = constructor01(arr);
  levelOderZigZag(root);
}

int main()
{
  solve();
  return 0;
}
