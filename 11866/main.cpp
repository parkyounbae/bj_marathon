#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> arr;

    int n,k;
    cin >> n >> k;



    for(int i=1 ; i<=n ; i++){
        arr.push(i);
    }

    cout << "<";

    while(!arr.empty()){
        for(int i=1 ; i<k ; i++){
            arr.push(arr.front());
            arr.pop();
        }

        cout << arr.front();
        arr.pop();

        if(!arr.empty()){
            cout <<", ";
        }
    }

    cout << ">" << '\n';


}
/*
 * 1234567 : 3
 * 456712 : 6
 * 71245 : 2
 * 4571 : 7
 * 145 : 5
 * 14 : 1
 * 4 : 4
 */