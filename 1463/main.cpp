#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001] = {0,};
int num;

void calc(int cnt){
    dp[1] = 0;
    for(int i=2 ; i<=num ; i++){
        dp[i] = dp[i-1] + 1;
        if(i%3 == 0){
            dp[i] = min(dp[i],dp[i/3]+1);
        }
        if(i%2 == 0){
            dp[i] = min(dp[i],dp[i/2]+1);
        }
    }
}

int main() {
    scanf("%d",&num);

    calc(num);

    printf("%d\n",dp[num]);


    return 0;
}

/*
2 1
 3 1
 4 2 1
 5 4 2 1
 6 2 1
 7 6 2 1
 8 4 2 1
 9 3 1
 10 9 3 1
 11 10 9 3 1
 12 4 2 1
 13 12 4 2 1
 14 7 6 2 1
 15 5 4 2 1
 16 8 4 2 1
 17 16 8 4 2 1
 18 6 2 1
 19 18 6 2 1
 20 10 9 3 1
 21 7 6 2 1
 22 11 10 9 3 1 / 22 21 7 6 2 1
 23 22 11 10 9 3 1
 24 12 4 2 1
 */