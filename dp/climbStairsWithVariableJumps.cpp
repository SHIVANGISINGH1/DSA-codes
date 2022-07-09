// In this problem we have variable jumps from a stair
// we can have max jumps = variable or make less jumps
// So accordingly we will add the paths considering the variable jumps

#include <iostream>
using namespace std;

int cs(int arr[], int num){
    
    int *temp = new int[(num+1)];
    
    for (int idx=0; idx<=num; idx++) temp[idx] = 0;
    
    temp[num] = 1;
    
    for (int idx= num-1; idx>=0; idx--) {
        
        int it = arr[idx];
        
        while(it>0) {
            
            if (idx+it <= num)
            temp[idx] += temp[idx+it];
            
            it-=1;
            
        }   
       
    }
    
    return temp[0];
}

int main(){

    int num;

    cin>>num;

    int arr[num];

    for(int i = 0 ; i < num ;i++){
        cin>>arr[i];
    }

    cout<<cs(arr,num)<<endl;
}