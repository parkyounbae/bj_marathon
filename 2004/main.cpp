#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    if(m==0 || m==n){
        cout << 0 <<endl;
        return 0;
    }

    int Count2=0,Count5=0;


    for(long long i=2 ; i<=n ; i=i*2) Count2 += n/i;
    for(long long i=2 ; i<=m ; i=i*2) Count2 -= m/i;
    for(long long i=2 ; i<=(n-m) ; i=i*2) Count2 -=(n-m)/i;

    for(long long i=5 ; i<=n ; i=i*5) Count5 += n/i;
    for(long long i=5 ; i<=m ; i=i*5) Count5 -= m/i;
    for(long long i=5 ; i<=(n-m) ; i=i*5) Count5 -=(n-m)/i;

    cout << min(Count2,Count5) << endl;


    return 0;
}
