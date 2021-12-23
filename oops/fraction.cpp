#include<bits/stdc++.h>
using namespace std;

class fraction{

    public: 
    int numerator;
    int denominator;

    fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print () {
        cout << numerator << "/" << denominator << endl;
    }

    void simplify() {
        int gcd = 1;
        int minVal = min(numerator,denominator);

        for (int it=1; it<minVal; it++) {
            if (numerator % it == 0 && denominator % it == 0) {
                gcd = it;
            }
        }

        numerator = numerator/gcd;
        denominator = denominator/gcd;
    }
    
// here in the argument istead of using fraction f1 I have used fraction const &f1 
// because instead of making a new object of class you can pass value by reference and make it
// constant so that no changes can be made in that

    void add (fraction const &f1) {
        int lcm = this->denominator * f1.denominator;
        int a1 = lcm/denominator * numerator;
        int a2 = lcm/f1.denominator * f1.numerator;

        numerator = a1 + a2;
        denominator = lcm;

        simplify(); 
    }

    void multipy(fraction const &f1) {
        numerator = numerator * f1.numerator;
        denominator = denominator * f1.denominator;

        simplify();
    }
};