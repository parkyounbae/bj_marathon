#include <iostream>
#include <algorithm>
using namespace std;

int height = 0;
int score[301] = {0,};
int memo[301] = {0,};

int main() {
    cin >> height;
    for(int i=0 ; i<height ; i++){
        cin >> score[i];
    }

    memo[0] = score[0];
    memo[1] = max(score[0]+score[1],score[1]);
    memo[2] = max(score[0]+score[2],score[1]+score[2]);
    for(int i=3 ; i<height ; i++){
        memo[i] = max(memo[i-2]+score[i],memo[i-3]+score[i-1]+score[i]);
    }
    printf("%d\n",memo[height-1]);

    return 0;
}
