#include<bits/stdc++.h>
using namespace std;

class Complex{
    private: 
    int real;
    int imaginary;

    public:
    Complex(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    void print() {
        cout << this->real << "+" << this->imaginary <<"i" << endl;
    }

    void add(Complex const &c2) {
        this->real = this->real + c2.real ;
        this->imaginary = this->imaginary + c2.imaginary;
    }

    void mutlipy(Complex const &c2) {
        int r = this->real * c2.real - this->imaginary * c2.imaginary;
        int i = this->real * c2.imaginary + this->imaginary * c2.real;
        this->real = r;
        this->imaginary = i;
    }
};