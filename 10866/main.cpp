#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int num;
    cin >> num;

    deque<int> arr;

    for(int i=0 ; i<num ; i++){
        string command;
        cin >> command;

        if(command == "push_front"){
            int tmp;
            cin >> tmp;
            arr.push_front(tmp);
        }else if(command == "push_back"){
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }else if(command == "pop_front"){
            if(arr.empty()){
                cout << -1 << '\n';
            }else{
                cout << arr.front() << '\n';
                arr.pop_front();
            }
        }else if(command == "pop_back"){
            if(arr.empty()){
                cout << -1 << '\n';
            }else{
                cout << arr.back() << '\n';
                arr.pop_back();
            }
        }else if(command == "size"){
            cout << arr.size() << '\n';
        }else if(command == "empty"){
            if(arr.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }else if(command == "front"){
            if(arr.empty()){
                cout << -1 << '\n';
            }else{
                cout << arr.front() << '\n';
                arr.front();
            }
        }else if(command == "back"){
            if(arr.empty()){
                cout << -1 << '\n';
            }else{
                cout << arr.back() << '\n';
                arr.back();
            }
        }
    }
    return 0;
}
