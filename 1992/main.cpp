#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int width;

void checkSquare(int x, int y, int depth, int** arr) {
    int startColor = arr[y][x];

    if(pow(2,depth)==width){
        if (startColor == 0){
            cout << 0;
        } else {
            cout << 1;
        }
        return;
    }

    for(int i=y ; i<y+width/pow(2,depth) ; i++) {
        for(int j=x ; j<x+width/pow(2,depth) ; j++) {
            if(arr[i][j] != startColor){
                cout << "(";
                checkSquare(x,y,depth+1,arr);
                checkSquare(x+width/pow(2,depth+1),y,depth+1,arr);
                checkSquare(x,y+width/pow(2,depth+1),depth+1,arr);
                checkSquare(x+width/pow(2,depth+1),y+width/pow(2,depth+1),depth+1,arr);
                cout << ")";
                return;
            }
        }
    }

    if (startColor == 0){
        cout << 0;
    }else{
        cout << 1;
    }
}

int main() {
    cin >> width;

    int** arr = new int*[width];
    for(int i=0 ; i<width ; i++){
        arr[i] = new int[width];
        memset(arr[i],0, sizeof(int)*width);
    }

    for(int i=0 ; i<width ; i++){
        string temp;
        cin >> temp;
        for(int j=0 ; j<width ; j++){
            if(temp.at(j) == '0'){
                arr[i][j] = 0;
            }else{
                arr[i][j] = 1;
            }
        }
    }

    checkSquare(0,0,0,arr);

    for(int i=0 ; i<width ; i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}
