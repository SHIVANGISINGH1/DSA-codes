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
// we will use a childQ and ParentQ we will first add root node to parentQ then Remove it 
// print its value (if it is empty then print next line)and add its children in the childQ then copy childQ to the parentQ
// repeat till both of them are not empty
Node* linearize(Node* node)
{
    queue<Node*> parentQ;
    queue<Node*> childQ;
    
    parentQ.push(node);
    
    while(parentQ.size() > 0 || childQ.size() > 0) {
        
        
        while(parentQ.size() > 0){
            Node* n = parentQ.front();
            parentQ.pop();
            cout << n->data << " ";
        
            if (parentQ.size() == 0)
                cout << endl;
            
            for (int idx=0; idx<n->children.size(); idx++) {
                childQ.push(n->children[idx]);
            }
        }
        
        while(childQ.size()>0) {
            Node* ne = childQ.front();
            childQ.pop();
            parentQ.push(ne);
        }
    }
}


// another approach using a dumy node

void linearize(Node* node)
{
    queue<Node*> main;
    Node* q = new Node(-1);
    
    main.push(node);
    main.push(q);
    
    while(main.size() > 0) {
        Node* n = main.front();
        
        
        if (n != q) {
            main.pop();
            cout << n->data << " ";
            
            for (int idx=0; idx<n->children.size(); idx++) {
                main.push(n->children[idx]);
            }
        }
        else {
            if (main.size() !=0) {
                main.pop();
                main.push(q);
                cout << endl;
            }
        }
        
        if (main.size() == 1) {
            if (main.front() == q) {
                main.pop();
            }
        }
    }
    
}

// another approach using size

void linearize(Node* node)
{
    queue<Node*> main;
    int size = 1;
    
    main.push(node);
    
    while(main.size() > 0) {
        size = main.size();
        while (size--) {
            Node* n = main.front();
            cout << n->data << " ";
            main.pop();
            
            for (int idx=0; idx<n->children.size(); idx++) {
                main.push(n->children[idx]);
            }
        }
        cout << endl;
    }
    
}


// using pair node

void linearize(Node* node)
{
    queue<pair<Node*,int>> q;
    
    q.push({node,1});
    int currLevel = 1;
    while(q.size() > 0) {
        Node* n = q.front().first;
        cout << n->data << " ";
        q.pop();
        
        for (int idx=0; idx<n->children.size(); idx++) {
            q.push({n->children[idx],currLevel+1});
        }
        
        if (q.front().second>currLevel) {
            cout << endl;
            currLevel = q.front().second;
        }
        
    }
    
}
int main()
{
    Node *root = takeInput();
    linearize(root);
}