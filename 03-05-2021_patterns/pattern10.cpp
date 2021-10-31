#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;
    
    int innerspaces= -1;              
    int outerspaces=lines/2;                                 // intially it is lines/2

    for (int LineNum=1; LineNum<=lines; LineNum++)
    {
        for (int spaces=1; spaces<=outerspaces; spaces++)      // first print outerspace
        {
            cout<<'\t';
        }

        cout<<"*\t";                                      // then star will print

        for (int spaces=1; spaces<=innerspaces; spaces++)
        {
            cout<<'\t';                                    // then innerspace 
        }

        if (lines!=1&&lines<lines)                   // second star will not be printed in first and last line                  
        {
            cout<<"*\t";
        }
        cout<<endl;

        if(lines<=lines/2)                       // in first half outerspace dec and innerspace inc by 2
        {
            outerspaces--;
            innerspaces+=2;
        }
        else                                     // in lower half innerspace dec by 2 and outerspace inc 
        {
           outerspaces++;                       
           innerspaces-=2;
        }
    }
    
    return 0;
}
//     pattern 10
//          *
//      *       *
//  *               *
//      *       *
//          *