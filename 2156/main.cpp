#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int dps[10001];
int num;

int main() {
    cin >> num;
    for(int i=1 ; i<=num ; i++){
        cin >> wine[i];
    }

    //if the last wine glass is n,
    // n + n-1 + n-3
    // n + n-2 + n-3
    // n-1 + n-2

    dps[1] = wine[1];
    dps[2] = wine[1] + wine[2];
    dps[3] = max(wine[2]+wine[3],wine[1]+wine[3]);
    dps[3] = max(dps[3],wine[1]+wine[2] );

    for(int i=4 ; i<=num ; i++){
        dps[i] = max(dps[i-3] + wine[i-1] + wine[i],dps[i-2]+wine[i]);
        dps[i] = max(dps[i],dps[i-1]);
        //cout << "dps[" << i << "] : " << dps[i] << endl;
    }

    printf("%d\n",dps[num]);

    return 0;
}
// 6 10 13 9 8 1
// 6 16 19