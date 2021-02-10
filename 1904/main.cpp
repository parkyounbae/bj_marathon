#include <iostream>
using namespace std;

int memo[1000001];

int zeroonetile(int num){
    if(num==1){
        memo[num] = 1;
        return 1;
    }else if(num == 2){
        memo[num] = 2;
        return 2;
    }else{
        if(memo[num]!=0){
            return memo[num];
        }else{
            memo[num] = zeroonetile(num-1) + zeroonetile(num-2);
            memo[num] = memo[num]%15746;
            return memo[num];
        }
    }
}

int main() {
    int num;
    cin >> num;

    cout << zeroonetile(num) << endl;

    return 0;
}
//1) 1
//2) 11 00
//3) 001 111 100
//4) 1111 0011 1001 1100 0000
//5) 11111 00111 10011 11001 11100 00001 00100 10000
//6) 111111 001111 100111 110011 111001 111100 110000 100100 100001 001100 000011 001001 000000