#include <iostream>

using namespace std;

int main() {
    int x,y,w,h;
    cin >> x >> y >> w >> h;

    //int left,right,up,down;
    int arr[4];
    arr[0] = x; arr[1] = w-x; arr[2]=h-y; arr[3]=y;

    int min=1000;

    for(int i=0 ; i<4 ; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }

    cout << min;
    return 0;
}
