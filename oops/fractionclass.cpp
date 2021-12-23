#include<bits/stdc++.h>
#include "fraction.cpp"
using namespace std;

int main() {

    fraction f1(12,5);

    f1.print();

    fraction f2(17,3);

    f2.add(f1);

    f2.print();

    fraction f3(13,6);

    f3.multipy(f1);

    f3.print();
}