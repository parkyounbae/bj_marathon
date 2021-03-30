#include <iostream>
using namespace std;

int main() {
    int circleNum;
    cin >> circleNum;
    int radArr[circleNum];

    for(int i=0 ; i<circleNum ; i++){
        cin >> radArr[i];
    }

    for(int i=1 ; i<circleNum ; i++){
        int tmpcir1 = radArr[0];
        int tmpcir2 = radArr[i];
        if(tmpcir1 > tmpcir2){
            for(int j=2 ; j<= tmpcir2 ;){
                if(tmpcir1%j==0 && tmpcir2%j==0){
                    tmpcir1 = tmpcir1/j;
                    tmpcir2 = tmpcir2/j;
                    j=2;
                }else{
                    j++;
                }
            }
        }else{
            for(int j=2 ; j<= tmpcir1 ;){
                if(tmpcir1%j==0 && tmpcir2%j==0){
                    tmpcir1 = tmpcir1/j;
                    tmpcir2 = tmpcir2/j;
                    j=2;
                }else{
                    j++;
                }
            }
        }
        cout << tmpcir1 << "/" << tmpcir2 << endl;
    }

    return 0;
}
