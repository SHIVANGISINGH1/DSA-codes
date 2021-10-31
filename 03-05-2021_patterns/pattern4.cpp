#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >>lines;
    
    int no_ofspaces=0;      // initially there are no spaces               
    int stars=lines;       //  intially stars are equal to no of lines

    for (int rows=1; rows<=lines; rows++)                     // iterate the loop lines number of times
    {
        for (int spaces=1; spaces<=no_ofspaces; spaces++)
        {
            cout<<'\t';
        }
        for (int column=1; column<=stars; column++)
        {
            cout<<"*\t";
        }
       
        cout<<endl;

        stars--;                          // stars are dec
        no_ofspaces++;                    // spaces are increasing
    }
    
     return 0;
}

//  pattern 4

//  *   *   *   *   *
//      *   *   *   *
//          *   *   *
//              *   *
//                  *
