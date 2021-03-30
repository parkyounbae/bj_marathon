#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int num;
    scanf("%d",&num);

    int arr[num];

    for(int i=0 ; i<num ; i++){
        scanf("%d",&arr[i]);
    }

    int max_ = arr[0];
    int dp[num];
    dp[0] = arr[0];

    for(int i=1 ; i<num ; i++){
        dp[i] = max(dp[i-1]+arr[i],arr[i]);
        max_ = max(dp[i],max_);
    }

    printf("%d\n",max_);

    return 0;
}
