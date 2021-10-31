#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;
    
    int no_ofspaces= 0;                  // intially there are no spaces

    for (int line=1; line<=lines; line++)
    {
         for (int spaces=1; spaces<=no_ofspaces; spaces++)
        {
             cout<<'\t';
        }

        cout<<"*"<<'\t';
        cout<<endl;

        no_ofspaces++;                   // spaces are increasing
    }

    return 0;
}
// pattern 7

//  *
//      *
//          *
//              *
//                  *