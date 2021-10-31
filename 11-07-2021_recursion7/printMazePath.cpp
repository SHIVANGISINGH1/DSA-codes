// we are doing the same thing as get maze paths the only difference is here we have to print our ans so as we make
// our ans we will return it 
// we will simply call the function twice one for col and other for row 
// and add h and v in our ans string
// same conditions as get maze paths

#include<iostream>
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

void printMazePaths(int sr, int sc, int dr, int dc, string ans)
{
    if (sr==dr && sc==dc)
    {
        cout << ans << "\n"; // hhvv
        
        return ;
    }
    
    if (sc<dc)
    {
        printMazePaths(sr, sc+1, dr, dc, ans + "h"); // 0,1,2,2,h 0,2,2,2,hh
    }

    if (sr<dr)
    {
        printMazePaths(sr+1, sc, dr, dc, ans + "v"); // 1,2,2,2,hhv 2,2,2,2,hhvv
    }
    
}

int main()
{
    int rows;
    int cols;

    cin >> rows >> cols;

    printMazePaths(0, 0, rows - 1, cols - 1, "");

    return 0;
}