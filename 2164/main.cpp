#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    if(num == 1){
        cout << "1" << '\n';
        return 0;
    }

    queue<int> arr;

    for(int i=1 ; i<=num ; i++){
        arr.push(i);
    }

    while(arr.size() > 1){
        arr.pop(); // 맨 앞에 하나 빼주고
        arr.push(arr.front());;
        arr.pop();
    }

    cout << arr.front() << '\n';



    return 0;
}


/*

짝수일때
 123456
 3456 2
 56 24
 246
 64
 4

12345678
 345678 2
 5678 24
 78 246
 2468
 68 4
 48
 8

12345678910
 246810
 48
 8

홀수일때
 1234567
 34567 2
 567 24
 7 246
 462
 26
 6

 */