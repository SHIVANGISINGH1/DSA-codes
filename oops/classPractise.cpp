// we will make a students class
#include<bits/stdc++.h>
using namespace std;

class student {
    public:
    int age;
    
    private:
    int rollNo;

    public:
    void setRN(int rollnumber) {
        rollNo = rollnumber;
    }
    int getRN() {
        return rollNo;
    }

};

int main() {
    student s1;
    s1.age = 24;
    s1.setRN(1);

    cout<<"s1 age:: "<<s1.age<<"\n";
    cout<<"s1 roll number:: "<<s1.getRN()<<"\n";

    student *s2 = new student;
    (*s2).age = 25;
    (*s2).setRN(2);

    cout<<"s2 age:: "<<(*s2).age<<"\n";
    cout<<"s2 roll number:: "<<(*s2).getRN()<<"\n";

    student *s3 = new student;
    s3 -> age = 26;
    s3 -> setRN(3);

    cout<<"s3 age:: "<<s3 -> age<<"\n";
    cout<<"s3 roll number:: "<<s3 -> getRN();
}