#include <iostream>

using namespace std;

int dp[31][31];

void binomial(int n,int m){
    if(m==0){
        dp[n][m] = 1;
    }else if(n==m){
        dp[n][m] = 1;
    }else if(m==1){
        dp[n][m] = n;
    }else if(dp[n-1][m-1]!=0 && dp[n-1][m]!=0){
        dp[n][m] = dp[n-1][m-1] + dp[n-1][m];
    }else{
        binomial(n-1,m-1);
        binomial(n-1,m);
        dp[n][m] = dp[n-1][m-1] + dp[n-1][m];
    }
}

int main() {
    int num;
    cin >> num;

    for(int i=0 ; i<num ; i++){
        int left,right;
        cin >> left >> right;
        binomial(right,left);
        cout << dp[right][left] << endl;
    }
    return 0;
}
