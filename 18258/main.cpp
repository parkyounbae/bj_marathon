#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int order;
    cin >> order;

    queue<int> q;
    string todo;

    for(int i=0 ; i<order ; i++){

        cin >> todo;

        if(todo.compare("push") == 0){
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }else if(todo.compare("pop") == 0){
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }else{
                cout << "-1" << '\n';
            }
        }else if(todo.compare("size") == 0){
            cout << q.size() << '\n';
        }else if(todo.compare("empty") == 0){
            if(q.empty()){
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }else if(todo.compare("front") == 0){
            if(q.empty()){
                cout << "-1" << '\n';
            }else{
                cout << q.front() << '\n';
            }
        }else if(todo.compare("back") == 0){
            if(q.empty()){
                cout << "-1" << '\n';
            }else{
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}