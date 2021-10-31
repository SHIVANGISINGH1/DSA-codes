// the method is similar to get Stair Path but instead of doing in post we just have to print our ans 
// we will call for num-1 num-2 and num-3 and add 1,2,3 in our psf(ans) string and will print when num is 0

#include <iostream>
using namespace std;

void printStairPaths(int num, string psf)
{
    if (num == 0)
    {
        cout<<psf<<"\num"; // 111 // 12 // 21 // 3
        
        return ;
    }
    
    printStairPaths(num-1,psf+"1"); // 2,1 1,11 0,111 0,21
    
    if (num-2>=0) // 2,1 // 3,0 
    {
        printStairPaths(num-2,psf + "2"); // 0,12 // 1,2 
    }
    
    
    if (num-3>=0) // 3,0
    {
        printStairPaths(num-3,psf + "3"); // 0,3
    }
    
}


int main()
{
    int num;

    cin >> num;

    printStairPaths(num,"");

    return 0;
}