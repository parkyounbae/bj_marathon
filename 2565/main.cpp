#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int left;
    int right;
} elecLine;

vector<elecLine> powerPoel;

int main() {
    int num;
    cin >> num;

    elecLine trash = {0,0};
    powerPoel.push_back(trash);

    for(int i=1 ; i<=num ; i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        elecLine tmpLine = {tmp1,tmp2};
        powerPoel.push_back(tmpLine);
    }

    for(int i=1 ; i<num ; i++){
        for(int j=i ; j<=num ; j++){
            if(powerPoel[j].right < powerPoel[i].right){
                elecLine tmp = powerPoel[j];
                powerPoel[j] = powerPoel[i];
                powerPoel[i] = tmp;
            }
        }
    }

    int dp[501] = {0,};
    int max_ = 0;

    for(int i=1 ; i<=num ; i++){
        int min_ = 0;
        for(int j=0 ; j<i ; j++){
            if(powerPoel[i].left > powerPoel[j].left){
                if(dp[j] > min_){
                    min_ = dp[j];
                }
            }
        }
        dp[i] = min_+1;
        if(dp[i] > max_){
            max_ = dp[i];
        }
    }

    cout << num - max_ << endl;

    return 0;
}

/*
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6

 4 2 6 7 9 1 3 10
 1 1 2 3 4 1 2 5
 */
