#include <iostream>
using namespace std;

int arr[12] = {0,};
int num = 0;
int operatorArr[4] = {0,};
int max_ = -1000000000;
int min_ = 1000000000;

void calc(int cnt,int before){
    if(cnt == num-1){
        if(before > max_){
            max_ = before;
        }
        if(before < min_){
            min_ = before;
        }
        return;
    }


        if(operatorArr[0]>0){
            operatorArr[0]--;
            calc(cnt+1,before+arr[cnt+1]);
            operatorArr[0]++;
        }
        if(operatorArr[1]>0){
            operatorArr[1]--;
            calc(cnt+1,before-arr[cnt+1]);
            operatorArr[1]++;
        }
        if(operatorArr[2]>0){
            operatorArr[2]--;
            calc(cnt+1,before*arr[cnt+1]);
            operatorArr[2]++;
        }
        if(operatorArr[3]>0){
            operatorArr[3]--;
            calc(cnt+1,before/arr[cnt+1]);
            operatorArr[3]++;
        }

}

int main() {
    cin >> num;
    for(int i=0 ; i<num ; i++){
        cin >> arr[i];
    }
    cin >> operatorArr[0] >> operatorArr[1] >> operatorArr[2] >> operatorArr[3];

    calc(0,arr[0]);

    cout << max_ << '\n' << min_ << '\n';

    return 0;
}
