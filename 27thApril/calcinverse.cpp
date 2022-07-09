#include<iostream>
#include<math.h>
using namespace std;


int findInv(int num) {

    // finding length
    int length = log10(num);
    
    int it = 1;
    int temp = num;
    int invNum = 0;

    while(length > 0) {

      
        int rem = temp % 10;
       // cout << rem;
        int add =  pow(10,rem-1);

        invNum += add * it;
        //cout << invNum;
        temp = temp/10;
        
        length--;
        it++;
    }

    return invNum;
}

int main() {

    int num; 

    cin >> num;

    cout << findInv(num);

    return 0;
}