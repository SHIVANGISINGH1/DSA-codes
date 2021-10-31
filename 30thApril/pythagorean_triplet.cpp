#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//code to check the given sides form pythagorean triplet or not

int main()

{
     int side1,side2,side3;

     cin >> side1 >> side2 >> side3;

    if (side1*side1== (side2*side2) + (side3*side3)
    ||side2*side2==  (side1*side1) + (side3*side3)
    ||side3*side3==  (side2*side2) + (side1*side1))

    cout<<"true";
    else
    cout<<"false";
}

     