#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str1;
    string str2;

    cin >> str1 >> str2;

    int dp[1001][1001] = {{0,},};

    int result = 0;

    for(int i=1 ; i<=str2.size() ; i++){
        for(int j=1 ; j<=str1.size() ; j++){
            if(str1.at(j-1) == str2.at(i-1)){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

            if(dp[i][j] > result){
                result = dp[i][j];
            }
        }
    }
    /*
     *  A C A Y K P
     *C 0 1 1 1 1 1
     *A 1 1 2 2 2 2
     *P 1 1 1 1 1 2
     *C 1 2 2 2 2 2
     *A 1 2 3 3 3 3
     *K 1 2 3 3 4 4
     * */




    cout << result << endl;

    return 0;
}
