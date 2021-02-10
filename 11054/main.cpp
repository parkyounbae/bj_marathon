#include <iostream>

using namespace std;

int main() {
    int arr[1001] = {0,};
    int dpIncrase[1001] = {0,};
    int dpDecrease[1001] = {0,};

    int num;
    cin >> num;

    for(int i=1 ; i<=num ; i++){
        cin >> arr[i];
    }

    for(int i=1 ; i<=num ; i++){
        int min_ = 0;
        for(int j=0 ; j<i ; j++){
            if(arr[j] < arr[i]){
                if(min_ < dpIncrase[j]){ //일단 I번째 숫자보다 비교하는 j번째의 숫자가 더 작아야 한다. + 기록해놓은 min보다 현재 비교하는 j번째의 dp가 더 커야한다.
                    min_ = dpIncrase[j]; //min을 업데이트 해준다. 최소의 기준을 높인다.
                }
                dpIncrase[i] = min_ + 1; //비교군보다 한단계 위 이므로 +1한 뒤 저장한다.
            }
        }
    }

    for(int i=num ; i>0 ; i--){
        int min_ = 0;
        for(int j=num+1 ; j>i ; j--){
            if(arr[i] > arr[j]){
                if(min_ < dpDecrease[j]){
                    min_ = dpDecrease[j];
                }
                dpDecrease[i] = min_ + 1;
            }
        }
    }

    int max = 0;
    for(int i=1 ; i<=num ; i++){
        if(max < dpIncrase[i]+dpDecrease[i]){
            max = dpIncrase[i]+dpDecrease[i];
            //cout << max << " " << dpIncrase[i] <<" "<<dpDecrease[i] << endl;
        }
    }


    cout << max -1;

    
    return 0;
}

/*
1 5 2 1 4 3 4 5 2 1

1 2 2 1 3 3 4 5 2 1
1 5 2 1 4 3 3 3 2 1
 */