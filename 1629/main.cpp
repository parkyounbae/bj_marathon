#include <iostream>

using namespace std;

int ipow(int a, int b, int c){
    if(b == 0) return 1;

    long long tmp = ipow(a, b/2, c);
    long long ans = (tmp * tmp) % c;
    if(b % 2 == 1) {
        ans *= a;
        ans %= c;
    }

    return ans;
}

int main() {
    int A,B,C;

    cin >> A >> B >> C;

    cout << ipow(A,B,C);


    return 0;
}

/*
 *
 * 2^1111 = 17*g(x) + r
 * x = 2^4
 * 8*x^277 = (x + 1)*g(x) + r
 */