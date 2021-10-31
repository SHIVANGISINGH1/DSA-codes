// It is similar to maze paths the difference is we can make jumps horizontaly,vertically and diagonally 
// So here we will call the function three times for horizontal , vertical , diagonal
// And here as we can make jumps and minimum jump = 1 we can make jumps till our jump is less than or equal to difference between 
// destination and source , the rest is same as maze path , calling the function and adding h , v and d
// In case of diagonal we will consider both conditions for horizontal and vertical for jumps 

#include<iostream>
#include<vector>
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        string base = "";
        
        vector<string> baseCase;
        
        baseCase.push_back(base);
        
        return baseCase;
    }

    vector<string> result;
    
    if(sc<dc)
    {
        for (int hJumps =1; hJumps<=dc-sc; hJumps++)
        {
            vector<string> pathHorizontal=getMazePaths(sr,sc+hJumps,dr,dc);
            
            int Size = pathHorizontal.size();
            
            for (int idx1=0; idx1<Size; idx1++)
            {
                result.push_back("h" + to_string(hJumps) + pathHorizontal[idx1]);
            }
        }
    }
    
    if(sr<dr)
    {
        for (int vJumps =1; vJumps<=dr-sr; vJumps++)
        {
            vector<string> pathVertical = getMazePaths(sr+vJumps,sc,dr,dc);
            
            int Size = pathVertical.size();
            
            for (int idx1=0; idx1<Size; idx1++)
            {
                result.push_back("v" + to_string(vJumps) + pathVertical[idx1]);
            }
            
        }
    }
    
    if(sr<dr && sc<dc)
    {
        for (int dJumps = 1; dJumps<=dc-sc && dJumps<=dr-sr; dJumps++)
        {   
            vector<string> pathdiagonal = getMazePaths(sr+dJumps,sc+dJumps,dr,dc);
        
            int Size = pathdiagonal.size();
            
            for (int idx1=0; idx1<Size; idx1++)
            {
                result.push_back("d" + to_string(dJumps) + pathdiagonal[idx1]);
            }
        }
    }

    return result;

}


void display(vector<string>& arr)
{
    cout << "[";

    for(int index = 0;index < arr.size();index++)
    {
        cout << arr[index];

        if(index < arr.size() -1) 
        {
            cout << ", ";
        }
    }
    
    cout << "]"<<endl;
}


int main() 
{
    int row,col; 
    
    cin >> row >> col;
    
    vector<string> ans = getMazePaths(1,1,row,col);

    display(ans);

    return 0;
}