#include <iostream>
using namespace std;

int arr[1001]; //배열 저장하기
int dp[1001]; //각 인덱스에 대한 배열순서 저장하기 만약 같은 수에 대해 배열이 중복이라면 더 큰걸 적용하기

int num;

int main() {
    cin >> num;
    for(int i=1 ; i<=num ; i++){
        cin >> arr[i];
    }

    int max = 0;

    for(int i=1 ; i<=num ; i++){
        int min = 0;
        for(int j=0 ; j<i ; j++){
            if(arr[i]>arr[j]){
                if(min < dp[j]){
                    min = dp[j];
                }
            }
            dp[i] = min + 1;
            if(max< dp[i]){
                max = dp[i];
            }
        }
    }

    printf("%d",max);

    return 0;
}
