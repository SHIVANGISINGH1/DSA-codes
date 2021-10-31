// Tower Oh Hanoi : 
// here we are given three towers and 2nd tower is the destination tower 
// here we will use the concept that if we are given 3 disks we will assume that 2 disks will reach the auxilary tower using destination
// and the left one disk will go to destination from tower1 then
// we will move the 2 disks from auxilary tower to destination tower so now our work is completed


#include<iostream>
using namespace std;

void towerOfHanoi(int noOfDisks, int tower1, int tower2, int tower3)
{
    if (noOfDisks == 1)
    {
        cout << noOfDisks << "[" << tower1 <<" " << "->" << " " << tower2 << "]" << endl; // 1: t1-> t2 =>1: t2-> t3 => 1: t3-> t1 => 1: t1-> t2
        return ;
    }

    towerOfHanoi(noOfDisks-1 , tower1 , tower3 , tower2); // 2,t1,t3,t2 -> 1,t1,t2,t3 -> 1,t3,t1,t2 

    cout << noOfDisks << "[" << tower1 << " " << "->" << " " << tower2 << "]" << endl; // 2: t1->t3 => 3: t1-> t2 => 2: t3-> t2

    towerOfHanoi(noOfDisks-1 , tower3 , tower2 , tower1); // 1,t2,t3,t1 -> 2,t3,t2,t1 -> 1,t1,t2,t3

    return ;    
}


int  main() 
{
    int noOfDisks;

    cin>>noOfDisks;

    int baseTower, destinationTower, auxilaryTower;

    cin >> baseTower >> destinationTower >> auxilaryTower;

    towerOfHanoi(noOfDisks, baseTower, destinationTower, auxilaryTower);

    return 0;
  }