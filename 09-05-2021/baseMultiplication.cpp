#include <iostream>
using namespace std;

// for adding the nums
int getadd(int base,int num1,int num2)
{
    int carry=0;
    int ans=0;
    int power=1;

    while(num1>0||num2>0||carry>0)

    {
        int digit1=num1%10;
        int digit2=num2%10;
        int add= digit1+digit2+carry;

        carry =add/base;
        add %=base;
        ans+= add*power;
        num1/=10;
        num2/=10;
        power*=10;
    }

    return ans;
}

// for the product
int GetProduct(int base,int num1,int num2)
{   
    int finalans=0;                              
    int OuterTensPalce=1;

    while(num2>0)                            // we will run the outerloop till num2 is greater then zero
    {
        int lastdigit2=num2%10;                                 
        int tempnum = num1; 
        int InnerTensPlace=1;
        int ans=0;
        int carry=0;

        while(tempnum>0||carry>0)         // in this we are multiplying single digit of num2 with num1 
        {                                                                   
            int lastdigit1=tempnum%10;
            int product = lastdigit1*lastdigit2 + carry;
            
            carry = product/base;
            product %= base;
            ans+= product*InnerTensPlace;
            InnerTensPlace*= 10;

            tempnum/=10;
            
        }
    
        finalans=getadd(base,finalans,ans*OuterTensPalce);          // we will call the add function and pass the ans * outertensplace
        OuterTensPalce*=10; 
        
        num2/=10;
    }
    
    return finalans;
}


int main()

{
	int base,num1,num2;

	cin>>base>>num1>>num2;

    cout<<GetProduct(base,num1,num2);
    
    return 0;

}