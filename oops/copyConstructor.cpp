#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    int age;

    private:
    long long int phoneNo;

    public:

    student (int age,long long int phoneNo) {
        this->age = age;
        this->phoneNo = phoneNo;
    }

    void display() {
        cout<<"AGE::"<<age<<endl;
        cout<<"PHONE NUMBER::"<<phoneNo<<endl;
    }
};

int main() {

    student mom(20,9871365366);
    mom.display();

    student brother(mom); // you can call copy constructor at the time of object creation
    brother.display();

    student *me = new student(21,9717281850);
    me->display();

    student sister(*me);
    sister.display();
}