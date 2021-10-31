#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;

    int no_ofspaces=lines-1;             // intially spaces(left) are lines-1

    for (int line=1; line<=lines; line++)
    {
        for (int spaces=1; spaces<=no_ofspaces; spaces++)
        {
            cout<<'\t';
        }
        
        cout<<"*\t";
        cout<<endl;

        no_ofspaces--;                    // spaces are dec
    }

    return 0;
}
//     pattern 8
//                  *
//              *
//          *
//      *
//  *