#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >>lines;

    for (int line=1; line<=lines; line++)
    {
        for (int stars=1; stars<=lines; stars++)
        {  
            if (stars==lines/2+1||line==lines/2+1
            ||line==1&&stars<=lines/2
            ||line==lines&&stars>lines/2
            ||stars==lines&&line<=lines/2
            ||stars==1&&line>lines/2)

            cout<<"*\t";
            else
            cout<<'\t';
        }
            cout<<endl;
    }

    return 0;
}
//  pattern 19
//  *   *   *       *
//          *
//  *   *   *   *   *
//  *       *
//  *       *   *   *