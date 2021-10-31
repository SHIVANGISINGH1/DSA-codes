#include<iostream>
using namespace std;

int getSum(int base, int num1, int num2)
{
    int lastdigit1,lastdigit2;
    int carry= 0;
    int ans=0;
    int power=1;
    int sum;

   while (num1!=0||num2!=0||carry>0)                 // we will iterate till any num is left or our carry is 1 
   {
       lastdigit1= num1 % 10;
       lastdigit2= num2 % 10;
       sum= lastdigit1 + lastdigit2 + carry;

       int ques = sum / base;                    // the ques will be the carry
       int rem = sum % base;    

       ans+= rem*power ;                       // rem multiplied with power will give ans and add it to get the entire sum
       carry= ques;
       power*= 10;
       
       num1= num1/10;
       num2= num2/10;
   }


   return ans; 
}  


int main() 
{
    int base, num1, num2;

    cin >> base >> num1 >> num2;

    cout << getSum(base, num1, num2) << endl;
    
    return 0;
}