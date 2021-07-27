#include <iostream>
#include <queue>

using namespace std;

int main() {
    int indexToPick[50];

    int sizeOfQueue, sizeToPick;
    cin >> sizeOfQueue >> sizeToPick;

    int move = 0;

    for(int i=0 ; i<sizeToPick ; i++) {
        cin >> indexToPick[i];
    }

    int indexOfArray = 0;

    while(sizeToPick > indexOfArray) {
        int moveToLeft = indexToPick[indexOfArray] - 1;
        int moveToRight = sizeOfQueue - indexToPick[indexOfArray] + 1;

        if(moveToLeft < moveToRight) {
            for(int i=indexOfArray ; i<sizeToPick ; i++){
                indexToPick[i] -= moveToLeft;
                if(indexToPick[i]<1){
                    indexToPick[i] = sizeOfQueue + indexToPick[i];
                }
            }
            move += moveToLeft;
            indexOfArray ++;
            sizeOfQueue --;
        }else{
            for(int i=indexOfArray ; i<sizeToPick ; i++) {
                indexToPick[i] += moveToRight;
                if(indexToPick[i] > sizeOfQueue){
                    indexToPick[i] = indexToPick[i] - sizeOfQueue;
                }
            }
            move += moveToRight;
            indexOfArray++;
            sizeOfQueue--;
        }

        for(int i=indexOfArray ; i<sizeToPick ; i++) {
            indexToPick[i]--;
        }
    }

    cout << move << endl;

    return 0;
}

/*
 * 1 2 3 4 5 6 7 8 9 10
 * 2 3 4 5 6 7 8 9 10 1 +
 * 3 4 5 6 7 8 9 10 1
 * 1 3 4 5 6 7 8 9 10 +
 * 10 1 3 4 5 6 7 8 9 +
 * 9 10 1 3 4 5 6 7 8 +
 * 10 1 3 4 5 6 7 8
 * ... ++++
 * 5 6 7 8 9 1 3 4
 */