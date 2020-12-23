#include <iostream>

using namespace std;

int main() {
    int a,b,v;

    cin >> a >> b >> v;
    //a:낮에 올라가는 높이 b:밤에 미끄러지는 높이 v:총 올라갈 높이

    int up = a-b;
    int except_last = v-a;

    if(except_last % up == 0){
        cout << except_last/up + 1 << endl;
    }else{
        cout << except_last/up + 2 << endl;
    }


    return 0;
}
