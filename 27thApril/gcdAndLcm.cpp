#include<iostream>
using namespace std;

  // to find gcd and lcm
int gcd(int num1, int num2)
{
  // we will divide till our remainder becomes zero
  // our divisor will be our dividend and the rem will become the divisor . At the end we will return the divisor

  while(num2!=0)
  {
    int rem= num1%num2;

    num1=num2;
    num2=rem;
  }

  return num1;
}
  

int main()
{
  int num1,num2;

  cin>>num1>>num2;

  cout<<gcd(num1,num2)<<endl;

  int lcm = (num1*num2)/gcd(num1,num2);

  cout<<lcm;

  return 0;
 
}