#include<iostream>
#include<vector>
using namespace std;

void seive(int num) {

    vector<int> vt(num + 1, 0);
  
    // check for prime 
    for ( int it = 2; it*it <= num; it++) {

        if (vt[it] == 0) {

            for (int mul = it*it; mul <= num; mul += it) {

                if(vt[mul] == 0) vt[mul] = 1;
            }
        }
    }

    // print all the prime nos 

    for (int it = 2; it <= num; it++) {

        if (vt[it] == 0) cout << it << " " ;
    }

}

int main() {

    int num;

    cin >> num;

    seive(num);

    return 0;
}