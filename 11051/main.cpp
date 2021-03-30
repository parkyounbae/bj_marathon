#include <iostream>

using namespace std;
int n,r;
int MAX = 10007;

void binomial(int a,int b,int** dp){
    if(a==b){
        dp[a][b]=1;
    }else if(b ==0){
        dp[a][b] = 1;
    }else if(b == 1){
        dp[a][b] = a;
    }else{
        if(dp[a-1][b-1]!=0 && dp[a-1][b]!=0){
            dp[a][b] = (dp[a-1][b-1]%MAX + dp[a-1][b]%MAX)%MAX;
        }else{
            binomial(a-1,b-1,dp);
            binomial(a-1,b,dp);
            dp[a][b] = (dp[a-1][b-1]%MAX + dp[a-1][b]%MAX)%MAX;
        }
    }
}

int main() {

    cin >> n >> r;

    //nCr = n-1 C r-1 + n-1 C r
    int** dp;
    dp = new int*[n+1];
    for(int i=0 ; i<=n ; i++){
        dp[i] = new int[r+1];
    }

    binomial(n,r,dp);

    cout << dp[n][r] << endl;

    for(int i=0 ; i<=n ; i++){
        delete[] dp[i];
    }
    delete [] dp;

    return 0;
}
