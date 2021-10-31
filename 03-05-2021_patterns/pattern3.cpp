#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;
    
    int no_ofspaces = lines-1;    // intially we have lines -1 spaces
    int stars=1;                 //  initially we have one star 

    for (int rows=1; rows<=lines; rows++)
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

        no_ofspaces--;      // spaces are decresing 
        stars++;           //  stars are incresing
    }
    
     return 0;
}

//  pattern 3
//                      *
//                  *   *
//              *   *   *
//          *   *   *   *
//      *   *   *   *   *