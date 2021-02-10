#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3];
int dp[1001][3];
int num;


int main() {
    cin >> num;
    for(int i=0 ; i<num ; i++){
        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    }

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for(int i=1 ; i<num ; i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + arr[i][2];
    }

    int minCost = min(dp[num-1][0],min(dp[num-1][1],dp[num-1][2]));
    printf("%d\n",minCost);

    return 0;
}
