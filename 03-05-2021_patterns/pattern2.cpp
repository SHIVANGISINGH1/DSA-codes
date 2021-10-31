#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;
   
   for (int row =1; row<=lines; row++)
   {
       for (int column=lines; column>=row; column--)   // as the 1st column has stars equal to lines and with dec in column stars decrease 
       {
           cout<<"*"<<'\t';
       }
       cout<<endl;
   }
   
   return 0;
}

// pattern 2

//  * * * * *
//  * * * *
//  * * *
//  * *
//  *