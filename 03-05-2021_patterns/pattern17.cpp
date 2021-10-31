#include <iostream>
using namespace std;
// arrow pattern

int main()
{
    int lines;

    cin >>lines;

    int no_ofstars=1;                       
    int no_ofspaces = lines/2; 
    int mid = lines/2+1;                                // for printing stars after the lines/2+1 line

    for(int line=1; line<=lines; line++)
    {   
        if(line==lines/2+1)                            // condition for lines/2+1 line no space all stars equal to lines
        {
            no_ofspaces=0;
            no_ofstars=lines;
        }

       if(line>lines/2+1)                             // condition for printing stars after lines/2+1 
        {   
            no_ofspaces=lines/2;
            no_ofstars=--mid;
        }
       
        for (int spaces=1; spaces<=no_ofspaces; spaces++)
        {
            cout<<'\t';
        }

        for (int stars=1; stars<=no_ofstars; stars++)
        {
            cout<<"*\t";
        }
        cout<<endl;
         
        if (line<=lines/2)
        {
            no_ofstars++;
        }
    }
    
    return 0;
}
//  pattern 17
//          *
//          *   *
//  *   *   *   *   *
//          *   *
//          *