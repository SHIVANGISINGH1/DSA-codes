#include<iostream>
#include<vector>
using namespace std;

void spf(int num) {

    int arr[num + 1];

    for (int it = 0; it<=num; it++) {
        arr[it] = it;
    }

    for (int it1=2; it1*it1 <= num; it1++) {

        if (arr[it1] == it1) {

            for (int it2 = it1*it1; it2<= num; it2 += it1) {

                if (arr[it2] == it2) arr[it2] = it1;
            }
        }
    }

    while(num != 1) {
        
        cout << arr[num] << "\n";
        num = num/arr[num];
        
    }
}




int main() {
    
    int num;

    cin >> num;

    spf(num);
    
    return 0;
}