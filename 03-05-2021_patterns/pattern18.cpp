#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;

    for (int line=1; line<=lines; line++)            // to print first line 
    {
        cout<<"*\t";
    }
    cout<<endl;

    int innerspaces=lines/2;                        // innerspace is intially lines/2
    int outerspaces=1;       

    // this loop is to print the upper half 
    
    for (int line=1; line<=lines/2; line++)
    {
        for (int spaces=1; spaces<=outerspaces; spaces++)
        {
            cout<<'\t';
        }

        cout<<"*\t";

        for (int spaces=1; spaces<=innerspaces; spaces++)
        {
            cout<<'\t';
        }

        if(line!=lines/2)                           // we will print only one star in lines/2 line 
        {
            cout<<"*\t";
        }

        for (int spaces=1; spaces<=outerspaces; spaces++)
        {
            cout<<'\t';
        }

        cout<<endl;
        outerspaces++;
        innerspaces-=2;

    }
   
    outerspaces=lines/2-1;
    
    int no_ofstars=lines/2;

    // this loop is for printing lower half

    for (int line=1; line<=lines/2; line++)
    {
        for (int spaces=1; spaces<=outerspaces; spaces++)
        {
            cout<<'\t';
        }

        for (int stars=1; stars<=no_ofstars; stars++)
        {
            cout<<"*\t";
        }

        cout<<endl;
        outerspaces--;
        no_ofstars+=2;
    
    }

    return 0;
}
// pattern 18
//  *   *   *   *   *   *   *
//      *               *
//          *       *
//              *   
//          *   *   *
//      *   *   *   *   *
//  *   *   *   *   *   *   *