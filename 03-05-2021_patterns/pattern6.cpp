#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;

    int no_ofspaces=1;                //initially we have one space
    int no_ofstars=lines/2+1;         // stars are lines/2+1 

    for (int lines=1; lines<=lines; lines++)
    {
        for (int stars=1; stars<=no_ofstars; stars++)
        {
            cout<<"*"<<'\t';
        }
        for (int spaces=1; spaces<=no_ofspaces; spaces++)              // spaces are inner spaces 
        {
            cout<<'\t';
        }
        for (int stars=1; stars<=no_ofstars; stars++)
        {
            cout<<"*"<<'\t';
        }
        cout<<endl;

        if(lines<=lines/2)                    // spaces are increasing by 2 and stars are dec till lines/2+1
        {
            no_ofstars--;
            no_ofspaces+=2;
        }
        else                                 // in lower half stars inc and spaces dec by 2
        {
            no_ofstars++;
            no_ofspaces-=2;
        }
    }
    
    return 0;
}
//              pattern 6
//      *   *   *       *   *   *
//      *   *               *   *
//      *                       *
//      *   *               *   *
//      *   *   *       *   *   *