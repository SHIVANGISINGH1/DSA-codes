// printKPC 
// Here we will take another parameter as answer string where we will form our ans string 
// we will call substr(1) and we will add our getchar[idx] which has the value of string codes   

#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string ans)
{
    if (ques.size()== 0)
    {   
        cout<<ans<<" "; // tv , tw , tx , uv , uw ,ux

        return ;
    }
    
    int digit = ques[0]-'0'; // 7 8  
    
    string getChar = codes[digit]; // tu // vwx
    
    int Size = getChar.size(); //  2 // 3
    
    for (int idx=0; idx<Size; idx++)    
    {
        printKPC(ques.substr(1) , ans + getChar[idx]) ;  // 8,""+t // "",t+v "",t+w "",t+x // 8, ""+u // "",u+v "",u+w "",u+x
    }
    
}


int main()
{
    string str;

    cin >> str;

    printKPC(str, "");

    return 0;
}