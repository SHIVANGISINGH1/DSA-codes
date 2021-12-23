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

    ~student() {
        cout<<"Destructor Called"<<endl;
    }
};

int main() {

    student s1(12,4567);

    student s2(23,653);

    s2 = s1;

    student *s3 = new student(23,4323467); 

    delete s3;// it will delete the memory at heap
}


