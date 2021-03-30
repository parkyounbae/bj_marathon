#include <iostream>

using namespace std;

int binomial(int n,int c){
    if(c==1){
        return n;
    }else{
        return n*binomial(n-1,c-1);
    }
}

int main() {
    int n,c;
    cin >> n >> c;

    if(c==0){
        cout << 1 << endl;
    }else{
        cout << binomial(n,c)/binomial(c,c) << endl;
    }
    return 0;
}
