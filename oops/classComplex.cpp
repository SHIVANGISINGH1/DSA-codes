#include<bits/stdc++.h>
#include "complex.cpp"
using namespace std;

int main() {

    int real1,imaginary1;
    int real2,imaginary2;

    cin >> real1 >> imaginary1 ;
    cin >> real2 >> imaginary2 ;

    Complex c1(real1,imaginary1);
    Complex c2(real2,imaginary2);

    c1.print();
    c2.print();

    c1.mutlipy(c2);
    c1.print();
}