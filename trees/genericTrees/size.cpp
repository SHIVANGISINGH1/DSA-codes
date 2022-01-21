#include <iostream>
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
 
// we will consider that size of root will be the sum of size of childrens plus one
// using this we will code 
// Time Complexity: 0(n) space Complexity: 0(n) worst case
int sizeOfTree(Node* node) {
    
    int size = 0;
    
    for (int idx=0; idx<node->children.size(); idx++) {
        int sizeChild = sizeOfTree(node->children[idx]);
        size = size + sizeChild;
        
    }
    
    size += 1;
    
    return size;
}

int main()
{
    Node *root = takeInput();
    
    cout<<sizeOfTree(root);
}