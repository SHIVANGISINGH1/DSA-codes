#include<iostream>
using namespace std;
// s pattern

int main()
{
    int lines;

    cin>>lines;

    for(int line=1; line<=lines; line++)
    {
        for (int stars=1; stars<=(lines/2)+2; stars++)
        {   
            
            if ((line==1)&&(stars>=2&&stars<=lines/2+1)
            ||((stars==1)&&(line>=2&&line<lines/2+1))
            ||((line==lines/2+1)&&(stars>=2&&stars<=lines/2+1))
            ||((line>lines/2+1&&line<lines)&&(stars==lines/2+2))
            ||line==lines&&(stars>=2&&stars<lines/2+2))
            
            cout<<"* ";
            else
            cout<<"  ";
        }

        cout<<endl;
    }
    
    return 0;
}