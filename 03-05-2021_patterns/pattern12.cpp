#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;
    
    int first =0;
    int second=1;
    int third;

    for (int NumOfLine=1; NumOfLine<=lines; NumOfLine++)
    {
        for (int num=1; num<=NumOfLine; num++)
        {
              cout<<first<<'\t';                     // we have to print fibonaci pattern
              third = first + second;
              first = second;
              second = third;
        }
        cout<<endl;
    }

    return 0;
}
// pattern 12
// 0
// 1    1
// 2    3   5
// 8    13  21  34