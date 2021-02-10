#include <iostream>

using namespace std;

int fac(int a){
    if(a != 0){
        return a*fac(a-1);
    }else{
        return 1;
    }
}

int main() {
    int num;
    cin >> num;

    if(num == 0){
        cout << 1 << endl;
    }else{
        cout << fac(num) << endl;
    }
    return 0;
}
