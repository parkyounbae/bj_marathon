#include <iostream>

using namespace std;

long long p = 1000000007;

long long pow(long long n, long long k){
    //n^k 구하기, 그냥 구하면 long long 범위를 넘어가기 때문에 계속 p에 대한 mod 계산을 해주어야 한다.
    //그냥 구하면 또 너무 헤비하니까 성질 이용해서 쪼갬 p^10 mod b = (p^5 mod b)*(p^5 mod b) mod b
    if (k == 0){
        return 1;
    } else if (k == 1){
        return n;
    } else if (k%2 == 1) {
        return (n*(pow(n,k-1)%p)) % p;
    } else {
        long long temp = pow(n,k/2)%p;
        return temp*temp%p;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    long long A = 1;
    long long B = 1;

    //N!
    for(int i=1 ; i<=N ; i++ ){
        A *= i ;
        A %= p ;
    }

    // (N-K)!
    for(int i=1 ; i<= N-K ; i++ ){
        B *= i;
        B %= p;
    }

    // (N-K)!K!
    for(int i=1 ; i<=K ; i++) {
        B *= i;
        B %= p;
    }

    /*
     * 여기서 왜 이렇게 하는가~!
     * 페르마의 소정리 : a^(p-1) = 1 mod p ... a* a^(p-2) = 1 mod p ... a의 역원 = a^(p-2)
     * A!/B! % MOD = A! * pow(B!,MOD-2) % MOD
     * 우리가 원하는 값을 구하기 위해서는 모듈러 계산을 해주어야 하는데 이 과정에는 나눗셈이 없다~ 그렇기 뗴문에 페르마의 소정리를 이용해
     * 분수꼴(나눗셈)이였던 식을 곱셈으로 바꿔주는것
     */

    cout << ( A * pow(B,p-2)) % p << endl;

    return 0;
}
