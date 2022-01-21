#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> commonEle(int *arr1, int len1, int *arr2, int len2) {
    vector<int> ans;
    unordered_map<int , bool> mp1;
   
    for (int idx=0; idx<len1; idx++) {
        if (mp1.count(arr1[idx]) > 0) {
            continue;
        }
        mp1.insert({arr1[idx],true});
    }
    
    vector<int> newarr2;
    unordered_map<int , bool> mp2;
   
    for (int idx=0; idx<len2; idx++) {
        if (mp2.count(arr2[idx]) > 0) {
            continue;
        }
        mp2.insert({arr2[idx],true});
        newarr2.push_back(arr2[idx]);
    }
    
  
    
    for (int idx=0; idx<newarr2.size(); idx++){
        if (mp1.count(newarr2[idx]) > 0) {
            ans.push_back(newarr2[idx]);
        }
    } 
    return ans;
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
    
    vector<int> print = commonEle(arr1, len1 , arr2 , len2);
    
    for (int idx=0; idx<print.size(); idx++) {
        cout << print[idx] << endl;
    }
}