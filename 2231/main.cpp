#include <iostream>

using namespace std;
int main() {
    int num;
    cin >> num;

    int tmp = num;
    int ten = 0;

    while(tmp>0){
        ten++;
        tmp = tmp/10;
    }

    for(int i=1 ; i<num ; i++){
        int resulttmp=0;
        tmp = i;
        for(int j=0 ; j<ten ; j++){
            resulttmp += tmp%10;
            tmp = tmp/10;
        }
        resulttmp += i;
        if(resulttmp == num){
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
