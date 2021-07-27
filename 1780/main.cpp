#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int width;
int numOfMinusOne = 0;
int numOfZero = 0;
int numOfOne = 0;

void checkNum(int x, int y, int depth, int** arr){
    int startNum = arr[y][x];

    if(pow(3,depth) == width){
        if(startNum == -1){
            numOfMinusOne++;
        }else if(startNum == 0){
            numOfZero++;
        }else{
            numOfOne++;
        }
        return;
    }

    for(int i=y ; i<y+width/pow(3,depth) ; i++){
        for(int j=x ; j<x+width/pow(3,depth) ; j++){
            if (arr[i][j] != startNum){
                checkNum(x,y,depth+1,arr);
                checkNum(x+width/pow(3,depth+1), y , depth+1, arr);
                checkNum(x+width/pow(3,depth+1)*2,y,depth+1,arr);

                checkNum(x,y+width/pow(3,depth+1),depth+1,arr);
                checkNum(x+width/pow(3,depth+1), y+width/pow(3,depth+1) , depth+1, arr);
                checkNum(x+width/pow(3,depth+1)*2,y+width/pow(3,depth+1),depth+1,arr);

                checkNum(x,y+width/pow(3,depth+1)*2,depth+1,arr);
                checkNum(x+width/pow(3,depth+1), y+width/pow(3,depth+1)*2 , depth+1, arr);
                checkNum(x+width/pow(3,depth+1)*2,y+width/pow(3,depth+1)*2,depth+1,arr);
                return;
            }
        }
    }
    if(startNum == -1){
        numOfMinusOne++;
    }else if(startNum == 0){
        numOfZero++;
    }else{
        numOfOne++;
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
        for(int j=0 ; j<width ; j++){
            cin >> arr[i][j];
        }
    }

    checkNum(0,0,0,arr);

    cout << numOfMinusOne << endl;
    cout << numOfZero << endl;
    cout << numOfOne << endl;

    for(int i=0 ; i<width ; i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}
