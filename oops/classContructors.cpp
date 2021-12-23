#include<iostream>
using namespace std;

class student {
    
    int age;
    int rollNo;

    public:

    student () {
         cout<<"constructer called"<<endl;
    }
    
    student(int rollNo,int age) {
        cout<<"constructor 2 called"<<endl;
        this->rollNo = rollNo;
        this->age = age;
    }



    void display() {
        cout<< "age :: " <<age<<"\n";
        cout<< "rollNo :: " <<rollNo<<"\n";
    }
};

int main() {
    student s1;
    
    student s3(1,24);
    
    s3.display();

    student *s2 = new student(2,25);

    s2->display();
    
}