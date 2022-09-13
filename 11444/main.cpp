#include <iostream>

using namespace std;
static int MOD = 1000000007;
long long** origin;

long long** multi(long long** arr,long long** arr2) {
    long long** result = new long long*[2];
    for(int i=0 ; i<2 ; i++) {
        result[i] = new long long[2];
    }

    for(int i=0 ; i<2 ; i++) {
        for(int j=0 ; j<2 ; j++) {
            for(int k=0 ; k<2 ; k++) {
                result[i][j] += arr[i][k] * arr2[k][j];
            }
            result[i][j] %= MOD;
        }
    }

    return result;
}

long long** pow(long long** arr, long long exp) {
    if (exp == 1) {
        return arr;
    }

    long long** result = pow(arr,exp/2);
    result = multi(result,result);

    if (exp%2 == 1) {
        result = multi(origin,result);
    }

    return result;
}

int main() {
    origin = new long long*[2];
    for(int i=0 ; i<2 ; i++) {
        origin[i] = new long long[2];
    }

    origin[0][0] = 1;
    origin[0][1] = 1;
    origin[1][0] = 1;
    origin[1][1] = 0;

    long long n;
    cin >> n;

    long long** result = pow(origin,n);

    cout << result[0][1];

    return 0;
}
