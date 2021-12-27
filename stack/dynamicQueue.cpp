// implement queue using arrays but make dynamic queue

#include <iostream>
#include <exception>
using namespace std;

class CustomQueue {
public:
  int* arr;
  int sizeQ;
  int front;
  int arrSize;

  CustomQueue(int cap) {
    sizeQ = 0;
    front = 0;
    arr = new int[cap];
    arrSize = cap;
  }

  int size() {
    return sizeQ;
  }

  void add(int data) {
      if (sizeQ == arrSize) {
            int *helperArr = new int[2*arrSize];
            
            for (int idx=0; idx<sizeQ; idx++) {
                int i = (front+idx) % arrSize;
                helperArr[idx] = arr[i];
            }
            
            arr = helperArr;
            arrSize = 2*arrSize;
            front = 0;
            int rear = (front + sizeQ)%arrSize;
            arr[rear] = data;
            sizeQ++;
      }
      else {
          int rear = (front + sizeQ)%arrSize;
          arr[rear] = data;
          
          sizeQ++;
      }
    
  }

  int peek() {
      if (sizeQ == 0) {
          cout << "Queue underflow" << endl;
          return -1;
      }
    else return arr[front];
  }

  int remove() {
    if (sizeQ == 0) {
          cout << "Queue underflow" << endl;
          return -1;
      }
      else
    {int y = arr[front];
    front = (front + 1)%arrSize;
    sizeQ--;

    return y;}
  }

  void display() {
    for (int idx=0; idx<sizeQ; idx++) {
        int i = (front + idx) % arrSize;
        cout << arr[i] <<" ";
    }
    cout << endl;
  }
};

int main() {
  int n;
  cin >> n;
  CustomQueue q(n);
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      q.add(val);
    }
    else if (str == "remove") {
      int val = q.remove();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = q.peek();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << q.size() << endl;
    }
    else if (str == "display") {
      q.display();
    }
    cin >> str;
  }
  return 0;
}