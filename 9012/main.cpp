#include <iostream>

using namespace std;

int main() {
    int t_case;
    cin >> t_case;

    for(int i=0 ; i<t_case ; i++){
        string tmp;
        cin >> tmp;
        int index = -1;
        char arr[tmp.size()];

        if(tmp.size() %2 != 0){
            cout << "NO" << endl;
        }else{
            int result = 0;
            for(int j=tmp.size()-1 ; j>=0 ; j--){
                if(tmp.at(j) == ')'){
                    index++;
                    arr[index] = ')';
                }else{
                    if(arr[index]==')'){
                        arr[index--] = ' ';
                    }else{
                        result = -1;
                        break;
                    }
                }
            }
            if(index == -1 && result!=-1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
