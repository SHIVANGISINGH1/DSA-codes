//          pattern 5
//             *
//         *   *   *
//     *   *   *   *   *
//         *   *   *
//             *


// spaces leftspace = rightspace = 2 1 0  n/2 stars = 1 1+2 1+2+2
// row n/2 + 1 stars = n, spaces = 0
// stars = row - 2 spaces = 1


int noOfSPaces = n/2;
int stars = 1;


for (int row=1; row<=n; row++) {

    for (int Lspace = 1; space<=noOfSPaces; spaces++) {
        cout << "\t";
    }

    for (int col=1; col<=stars; col++) {
        cout << "*\t";
    }

    for (int Lspace = 1; space<=noOfSPaces; spaces++) {
        cout << "\t";
    }
    if (row <= n/2 + 1) { 
        noOfSPaces--;
        stars+=2;
    }
    else {
        noOfSPaces++;
        stars-=2;
    }
    cout << "\n";
}