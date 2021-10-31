#include<iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;                                      //lines=no of lines

    int nspaces = lines/2;                             // nspaces are number of spaces 
    int nele = 1;                                      //nele= no of elements(or column)
    int toprint = 1;                                   // toprint represent the number to be printed  

    for(int line = 1 ; line <= lines ; line++)          //line = rows
    {
        for(int spaces =1 ; spaces<= nspaces ; spaces++)          
        {
            cout<<'\t';
        }

        for(int ele = 1 ; ele <= nele ; ele++)          //ele=element
        {
            cout << toprint <<'\t';
            if(ele <= nele/2)  
            {                                
                toprint++;
            }                            
    
            else
            {
               toprint--;
            }
        }

        if(line <= lines/2)
        {
            nspaces--;                                      // spaces are dec
            toprint+=2;                                    // we will inc the num with 2
            nele+=2;                                      // no of elements are inc by 2 till lines/2+1
        }

        else
        {
            nspaces++;
            nele-=2;
        }

        cout<<'\t';
    }
    
    return 0;
}
// Pattern 15
//          1
//      2   3   2     
//  3   4   5   4   3
//      2   3   2
//          1