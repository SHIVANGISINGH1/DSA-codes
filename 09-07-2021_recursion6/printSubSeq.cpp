// we are calling the function twice for substr(1) and then
// we are first adding empty ("") string and then firstCharacter of the string
// and when string size is empty we will print our ans


#include<iostream>
using namespace std;

void printSubSeq(string ques, string ans)
{
    if (ques.size()== 0)
    {
        cout<<ans<<" ";
        
        return ;
    }

    char firstchar = ques[0]; 

    printSubSeq(ques.substr(1), ans + firstchar); // calling the function twice 

    printSubSeq(ques.substr(1), ans + ""); 

    return ;
}

int main()
{
    string str;

    cin >> str;

    printSubSeq(str, "");

    return 0;
}