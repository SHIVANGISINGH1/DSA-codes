// Here we have to print encoding of the given string
// first we are just converting each string into its alphabet till it is completely converted and then return 
// then we are taking pairs converting them and checking if they lie in the range and converting them and calling for substr(2) to 
// convert another pair  
// take string as 123 ans -> abc,aw,lc

#include<iostream>
#include<string>
using namespace std;

void printEncoding(string str, string ans)
{

    if (str[0] == '0')
    {
        return;
    }
    
    if (str.size() == 0)
    {
        cout << ans << "\n";  // abc // aw // lc
        
        return ;
    }
    
    char ch = str[0]-'0';  // 1 2 3 // 3
    char store = ch + 'a' -1;  // a b c // c
    
    printEncoding (str.substr(1), ans + store);  // bc,a c,ab ,abc // ,lc
    
    if (str.size()!=1)
    {
        string save="";

        save+= str[0];  // b // a
        save+= str[1];  // bc // b
        
        if (stoi(save)>=10 && stoi(save)<=26) 
        {
            int convert = stoi(save);  // 23 // 12

            convert = convert + 'a' - 1;  // 23 // 12
            
            printEncoding (str.substr(2), ans+(char)convert); // ,aw c,l
        }
    }
}


int main()
{
    string str;
    
    cin>>str;
    
    printEncoding(str,"");
    
    return 0;    
}