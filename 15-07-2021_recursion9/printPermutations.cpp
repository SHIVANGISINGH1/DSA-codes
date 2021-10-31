// Here we have to print all the permutations of abc 
// so first we will swap the value at first index with idx(from for loop idx = 0,1,2)
// now in our ans string we will add the character at first index 
// and we will pass substr(1) and sNew in our function

// we are basically doing
// abc -> bc,a 
// bc,a -> c,ab -> ,abc(print) -> RETURN to bc,a -> cb,a -> b,ac -> ,acb(print)... 

#include<iostream>
using namespace std;

void printPermutations(string str, string ans)
{
    
   if (str.size()==0)
   {
       cout << ans << "\n";

       return ;
   }
    
    for (int idx=0; idx<str.size(); idx++)
    {
       char temp = str[0];
       str[0] = str[idx];
       str[idx] = temp; 
       
       string sNew = ans + str[0];
       
       printPermutations(str.substr(1),sNew);
   }
   
}


int main()
{
    string str;

    cin>>str;

    printPermutations(str,"");
    
    return 0;
}