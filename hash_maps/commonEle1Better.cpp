#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void commonEle(int *arr1, int len1, int *arr2, int len2) {
   
    unordered_map<int , int> mp1;
   
    for (int idx=0; idx<len1; idx++) {
        if (mp1.count(arr1[idx]) > 0) {
            mp1.at(arr1[idx])++;
        }
        mp1.insert({arr1[idx],1});
    }
    
 
    for (int idx=0; idx<len2; idx++) {
        if (mp1.count(arr2[idx]) > 0) {
            cout << arr2[idx] << endl;
            mp1.erase(arr2[idx]);
        }
    }
    
 
}



int main() {
    
    int len1;
    
    cin >> len1;
    
    int arr1[len1];
    
    for (int idx=0; idx<len1; idx++) {
        cin >> arr1[idx];
    }
    
    int len2; 
    
    cin >> len2; 
    
    int arr2[len2];
    
    for (int idx=0; idx<len2; idx++) {
        cin >> arr2[idx];
    }
    
    commonEle(arr1, len1 , arr2 , len2);
    
}