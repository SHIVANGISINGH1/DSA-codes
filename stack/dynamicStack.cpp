// in this we have to make a dynamic version of the stack using array
#include <iostream>
#include <exception>
using namespace std;

class Stack {

public:
  int* arr;
  int tos;
  int MaxCapacity;

public:
  Stack(int size) {
    this->MaxCapacity = size;
    this->arr = new int[this->MaxCapacity];
    this->tos = -1;
  }

public:
  Stack() {
    Stack(10);
  }

public:
  int size() {
    return tos+1;
  }

public:
  void push(int data) {
      
      if (tos >= MaxCapacity-1) {
         int *n = new int[MaxCapacity*2];
         
         for (int idx=0; idx<=tos; idx++) {
             n[idx] = arr[idx];
         }
         
         arr = n;
         tos+=1;
         arr[tos] = data;
         
         
      }
      else {
        tos +=1; 
        arr[tos] = data;
      }
  }

public:
  int top()
  {
    if (tos == -1) {
      cout << "Stack underflow" << endl;
      return -1;
    }
    else
    return arr[tos]; 
  }

public:
  int pop()
  {
    if (tos == -1) {
      cout << "Stack underflow";
      return -1;
    }
    else {
      int y =  arr[tos];
      tos-=1 ;
      return y;
    }
  }

public:
  void display() {
    
    int size = MaxCapacity;

    for (int idx=tos; idx>=0; idx--) {
      cout << arr[idx] <<" ";
    }
    cout<<endl;
  }
};

int main() {
  int n;
  cin >> n;
  Stack st(n);
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "push") {
      int val;
      cin >> val;
      st.push(val);
    } else if (str == "pop") {
      int val = st.pop();
      if (val != -1) {
        cout << val << endl;
      }
    } else if (str == "top") {
      int val = st.top();
      if (val != -1) {
        cout << val << endl;
      }

    } else if (str == "size") {
      cout << st.size() << endl;
    } else if (str == "display") {
      st.display();
    }
    cin >> str;
  }
}