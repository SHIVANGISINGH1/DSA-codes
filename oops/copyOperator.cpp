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


// now if you want to copy properties of one object to other but after the creation of the object 
// use copy operator

int main() {

    student s1(12,98765332);
    s1.display();
    student s2(23,98765432);
    s2.display();

    s2 = s1;

    s2.display();

    student *s3 = new student(23,765432578);

    s2 = *s3;

    s2.display();

}