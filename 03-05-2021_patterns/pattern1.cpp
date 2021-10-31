#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;
    
   for (int row =1; row<=lines; row++)
   {
       for (int column=1; column<=row; column++)         // as in the pattern row number equal to num of stars
       {
           cout<<"*"<<'\t';
       }
       cout<<endl;
   }
   
   return 0;
}

//  pattern 1
//  *
//  * *
//  * * *
//  * * * *
//  * * * * *
