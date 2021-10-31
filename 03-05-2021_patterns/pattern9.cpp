#include <iostream>
using namespace std;

int main()
{
    int NumOfLines;

    cin >> NumOfLines;

    int outerspaces =0;                 // intially there is no outerspace
    int innerspaces =NumOfLines-2;      // initailly inner space is no of lines-2

    for (int lines=1; lines<=NumOfLines; lines++)    
    {
        for (int spaces=1; spaces<=outerspaces; spaces++)          // first we will give outer space
        {
            cout<<'\t';
        }

        cout<<"*"<<'\t';                                        // then we will print one star

        for(int spaces=1; spaces<=innerspaces; spaces++)          // then print inner space 
        {
            cout<<'\t';
        }

        if(lines!=NumOfLines/2+1)            // we have to print the second star after innerspace in all lines except no of lines/2+1
        {
            cout<<"*\t";
        }
        cout<<endl;

        if (lines<=NumOfLines/2)                                 // outerspaces wii inc and innerspace dec by 2 till num of lines/2
        {
           outerspaces++;
           innerspaces-=2;
        }
        else
        {
            outerspaces--;                                 
            innerspaces+=2;
        }
    }
    
     return 0;
}
//      pattern 9
//  *               *
//      *       *
//          *
//      *       *
//  *               *