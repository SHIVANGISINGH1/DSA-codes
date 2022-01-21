#include <bits/stdc++.h>
#include <vector>
#include <stack>

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

int sizeTree = 0;
int maximum = INT_MIN;
int minimum = INT_MAX;
int height = 0;

void multisolver(Node* node,int depth) {
    sizeTree++;
    maximum = max(maximum,node->data); 
    minimum = max(minimum,node->data);
    height = max(height,depth);

    for (int idx=0; idx<node->children.size(); idx++) {
        multisolver(node->children[idx],depth+1);
    }
}


int main()
{
    Node *root = takeInput();
    
}