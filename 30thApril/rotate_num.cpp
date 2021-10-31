#include <iostream>
#include<cmath>
using namespace std;

// function to claculate the number of digits

int digits(int num)

{ 
    int count =0;

    while(num>0)
    {
        num/=10;
        count++;
    }
        return count;
}
 
 // function to rotate the given number

int rotatenum(int num1,int k)

 {   
      
    // we will divide the num into two parts first we will divide it with 10 raised to power k, and we will store the ques and rem
    // rem will come in front and ques at the end and the num is rotated  
    int count = digits(num1);
    int div = pow(10,k);
    int ques= num1/div;
    int rem = num1%div;
    int ans = rem*pow(10,count-k)+ques;

    return ans;
}


 int main()
 {
    int num,k;  // K is the number of times we are rotating the input num

    cin>>num>>k;
    int count =digits(num);
    k = k%count;
    if (k<0)
    {
    k =-k;
    k = count-k;
    }
    cout<<rotatenum(num,k);
 }