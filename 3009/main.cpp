#include <iostream>

using namespace std;

int main() {
    int x[3];
    int y[3];

    for(int i=0 ; i<3 ; i++){
        cin >> x[i] >> y[i];
    }

    int x4,y4;

    if(x[0]-x[1] == 0){
        x4 = x[2];
    }else if(x[0]-x[2] == 0){
        x4 = x[1];
    }else{
        x4 = x[0];
    }

    if(y[0]-y[1] == 0){
        y4 = y[2];
    }else if(y[0]-y[2] == 0){
        y4 = y[1];
    }else{
        y4 = y[0];
    }

    cout << x4 << " " << y4;
    return 0;
}
