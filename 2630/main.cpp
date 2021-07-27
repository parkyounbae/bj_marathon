#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int white = 0;
int black = 0;
int width = 0;

void checkColor(int x, int y, int depth, int** arr){
    int startColor = arr[x][y];

    if (pow(2,depth) == width){
        if(startColor == 1){
            black++;
        }else{
            white++;
        }
        return;
    }

    for(int i=y ; i<y+width/pow(2,depth) ; i++){
        for(int j=x ; j<x+width/pow(2,depth) ; j++){
            if (startColor != arr[j][i]){
                checkColor(x,y,depth+1,arr);
                checkColor(x+width/pow(2,depth+1),y,depth+1,arr);
                checkColor(x,y+width/pow(2,depth+1),depth+1,arr);
                checkColor(x+width/pow(2,depth+1),y+width/pow(2,depth+1),depth+1,arr);
                return;
            }
        }
    }

    if(startColor == 1){
        black++;
    }else{
        white++;
    }

}

int main() {
    cin >> width;
    int **arr = new int*[width];
    for(int i=0 ; i<width ; i++){
        arr[i] = new int[width];
        memset(arr[i],0, sizeof(int)*width);
    }

    for(int i=0 ; i<width ; i++) {
        for(int j=0 ; j<width ; j++){
            cin >> arr[i][j];
        }
    }

    checkColor(0,0,0,arr);

    cout << white << endl;
    cout << black << endl;

    for(int i=0 ; i<width ; i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}
