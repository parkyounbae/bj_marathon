#include <iostream>
using namespace std;
long long int dp[101][10];
long long int result[101] = {0,};
int digit = 0;

int main() {
    scanf("%d",&digit);
    result[1] = 9;
    for(int i=0 ; i<10 ; i++){
        dp[1][i] = 1;
    }

    for(int i=2 ; i<=digit ; i++){
        dp[i][0] = dp[i-1][1];

        for(int j=1 ; j<10 ; j++){
            if(j==9){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
            }
            result[i] += dp[i][j];
        }
        result[i] = result[i]%1000000000;
    }

    printf("%lld\n",result[digit]);

    return 0;
}
/*
 10 12 23 34 45 56 67 78 89
 21 32 43 54 65 76 87 98

 123 121 234 232 212 323 321 345 343
 */