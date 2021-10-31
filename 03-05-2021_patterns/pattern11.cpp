#include <iostream>
using namespace std;

int main()
{
    int lines;

    cin >> lines;

    int num=1;

    for (int rows=1; rows<=lines; rows++)
    {
        for (int column=1; column<=rows; column++)
        {
            cout<<num<<'\t';                  // we will print num and increment it by 1
            num++;
        }
        
        cout<<endl;
    }

    return 0;
}
// pattern 10
//  1
//  2   3
//  4   5   6
//  7   8   9   10