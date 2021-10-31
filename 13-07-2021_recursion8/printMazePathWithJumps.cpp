// Similar to maze paths with jumps 
// Here we will call the function thrice for horizontal , vertical and diagonal and run loop for jumps (refer maze path with jumps)
// on each call we will add h or(v,d) , idx to our ans string  
// print ans when we reach destination i.e sourceCol is equal to destinationCol and sourcrRow is equal to destinationRow


#include<iostream>
using namespace std;

void printMazePaths(int sourcrRow, int sourceCol, int destinationRow, int destinationCol, string ans) 
{
    if (sourceCol == destinationCol && sourcrRow == destinationRow)
    {   
        cout << ans << "\n";

        return ;
    }
    
    if (sourceCol < destinationCol)
    {
        for (int idx=1; idx <= destinationCol-sourceCol; idx++)
        {
            printMazePaths(sourcrRow, sourceCol+idx, destinationRow, destinationCol, ans + "h" + to_string(idx));
        }
    }
    
    if (sourcrRow < destinationRow)
    {
        for (int idx=1; idx <= destinationRow-sourcrRow; idx++)
        {
            printMazePaths(sourcrRow+idx, sourceCol, destinationRow, destinationCol, ans + "v" + to_string(idx));
        }
    }
    
    if (sourcrRow < destinationRow && sourceCol < destinationCol)
    {
        for (int idx=1; idx <= destinationCol-sourceCol && idx <= destinationRow-sourcrRow; idx++)
        {
            printMazePaths(sourcrRow+idx, sourceCol+idx, destinationRow, destinationCol, ans + "d" + to_string(idx));
        }
    }
}


int main() 
{
    int row;
    int col;

    cin>>row>>col;

    printMazePaths(1, 1, row, col, "");

    return 0;
}