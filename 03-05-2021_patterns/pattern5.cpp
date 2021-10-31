#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >>lines;

    int no_ofspaces=lines/2;                  // as intially spaces(left) are equal to lines/2
    int no_ofstars=1;                         // as there is only one star in the begnining
   
    for (int rows=1; rows<=lines; rows++)
    {
        for (int spaces=1; spaces<=no_ofspaces; spaces++)
        {
            cout<<'\t';
        }
        for (int stars=1; stars<=no_ofstars; stars++)
        {
            cout<<"*\t";
        }
        cout<<endl;

        if (rows<=lines/2)                  // we will inc stars and dec spaces in the upper half which is lines+1/2
        {
            no_ofstars+=2;
            no_ofspaces--;
        }
        else                                // we will decrease stars and inc spaces in lower half
        {
            no_ofspaces++;
            no_ofstars-=2;
        }
    }

     return 0;
}
 //          pattern 5
 //             *
 //         *   *   *
 //     *   *   *   *   *
 //         *   *   *
 //             *
