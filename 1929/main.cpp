#include <iostream>

using namespace std;
int isPrime(int num){
    //소수 고려할사항 1,2 주목!
    if(num ==1){
        return 0;
    }else if(num == 2){
        return 1;
    }

    for(int i=2;i*i<=num;i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main() {
    int m,n;
    cin >> m >> n;

    for(int i=m ; i<=n ; i++){
        if(isPrime(i)==1){
            cout << i << endl;
        }
    }
    return 0;
}
