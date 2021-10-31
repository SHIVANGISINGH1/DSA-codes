#include <iostream>
using namespace std;
int main()
{
    int lines;

    cin >> lines;

    int no_ofspaces= 2*(lines)-3;                              // innerspaces are calculated and are equal to this                    
    int number=1;                                              // for columns

    for (int line=1; line<=lines; line++)
    {
        for (int column=1; column<=number; column++)
        {
            cout<<column<<'\t';                                 // print the num  ( column = num )
        }
        for (int spaces=1; spaces<=no_ofspaces; spaces++)     // for spaces
        {
            cout<<'\t';
        }

        if(line==lines)                                     // in the last line we will not print one more 4(=lines) 
        {
            number=number-1;
        }

        for (int column=number; column>=1; column--)       // for printing the right side nos in dec order
        {
            cout<<column<<'\t';
        }
        cout<<endl;
        no_ofspaces-=2;                                    // spaces are dec by 2
        number+=1;                                        //  number is inc by 1 
    } 

    return 0;
}
//  pattern 16
//  1                       1
//  1   2               2   1
//  1   2   3       3   2   1
//  1   2   3   4   3   2   1