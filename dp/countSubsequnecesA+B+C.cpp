// In this question we were given a expression 'abcabc' we need to print all subsequences with
// a+b+c+ format


#include<iostream>
using namespace std;

int countSub(string inp) {

    int a = 0;
    int ab = 0;
    int abc = 0;

    for (int idx=0; idx<inp.size(); idx++) {
        if (inp[idx] == 'a') {
            a = 2*a + 1;
        }
        else if (inp[idx] == 'b') {
            ab = 2*ab + a;
        }
        else {
            abc = 2*abc + ab;
        }
    }

    return abc;
}


int main() {

    string inp;

    cin >> inp;

    cout << countSub(inp);
}