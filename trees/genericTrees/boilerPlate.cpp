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

Node* linearize(Node* node)
{
    vector<Node*> arr;
    
    arr.push_back(node);
    arr.push_back(NULL);
    
        
        for (int idx=0; idx<arr.size(); idx++) {
            if (arr[idx] == NULL) {
              arr.push_back(NULL);  
            }
            else {
                Node* n = arr[idx];
                for (int idx1=0; idx1<n->children.size(); idx1++) {                   arr.push_back(n->children[idx1]);
                }
            }
        }
    
    
    for (int idx=0; idx<arr.size(); idx++) {
        if (arr[idx] == NULL) {
            cout << endl;
        }
        else {
            cout << arr[idx]->data;
        }
    }
}

int main()
{
    Node *root = takeInput();
    
}