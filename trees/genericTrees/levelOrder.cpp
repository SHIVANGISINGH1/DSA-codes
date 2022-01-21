#include <iostream>
#include <vector>
#include <stack>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }

    ~Node()
    {
        int size = children.size();
        for (int index = 0; index < size; index++)
        {
            delete children[index];
        }
    }
};

Node *takeInput()
{
    int size;

    cin >> size;

    int *input = new int[size];

    for (int index = 0; index < size; index++)
    {
        cin >> input[index];
    }

    Node *root = NULL;

    stack<Node *> nodes;

    for (int index = 0; index < size; index++)
    {
        if (input[index] == -1)
        {
            nodes.pop();
        }

        else
        {
            Node *newNode = new Node(input[index]);

            if (nodes.size() == 0)
            {
                root = newNode;
            }

            else
            {
                nodes.top()->children.push_back(newNode);
            }

            nodes.push(newNode);
        }
    }

    return root;
}
// here in this problem we will RPA 
// we will use a queue insert the node remove it print its value and then add its children

void levelorder(Node* node)
{
  queue<Node*> mainQ;
  mainQ.push(node);
  
  while(mainQ.size() > 0) {
      
      Node* n = mainQ.front(); 
      
      mainQ.pop(); // remove     
      
      cout << n->data << " "; // print
     
      
      for (int idx=0; idx<n->children.size(); idx++) {
          mainQ.push(n->children[idx]); // add
      }
      
      
  }
  
  cout << ".";

}
int main()
{
    Node *root = takeInput();
    levelorder(root);
}