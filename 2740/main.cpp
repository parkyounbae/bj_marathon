#include <iostream>

using namespace std;

int main() {
    int aWidth,aHeight,bWidth,bHeight;

    cin >> aHeight >> aWidth;

    int** arrA = new int*[aHeight];
    for(int i=0 ; i<aHeight ; i++) {
        arrA[i] = new int[aWidth];
    }

    for(int i=0 ; i<aHeight ; i++) {
        for(int j=0 ; j<aWidth ; j++) {
            cin >> arrA[i][j];
        }
    }

    cin >> bHeight >> bWidth;

    int** arrB = new int*[bHeight];
    for(int i=0 ; i<bHeight ; i++) {
        arrB[i] = new int[bWidth];
    }

    for(int i=0 ; i<bHeight ; i++) {
        for(int j=0 ; j<bWidth ; j++) {
            cin >> arrB[i][j];
        }
    }

    for(int i=0 ; i<aHeight ; i++) {
        for(int j=0 ; j<bWidth ; j++) {
            int sum = 0;
            for(int k=0 ; k<aWidth ; k++) {
                sum += arrA[i][k]*arrB[k][j];
            }
            cout << sum << " ";
        }
        cout << "\n";
    }

    return 0;
}
