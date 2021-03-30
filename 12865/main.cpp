#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct {
    int W;
    int V;
}Thing;

int main() {
    int N,K; //N=물건의 갯수, K=버틸 수 있는 무게
    cin >> N >> K;
    Thing arr[101];

    for(int i=1 ; i<=N ; i++){
        cin >> arr[i].W >> arr[i].V;
    }



    int dp[N+1][K+1];
    memset(dp,0,sizeof(dp));

    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=K ; j++){
            if(j - arr[i].W >= 0){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i].W] + arr[i].V);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}
