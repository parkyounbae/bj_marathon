#include <iostream>
#include <sstream>
#include <cstdlib>
#include <deque>

using namespace std;

int main() {
    int t_case;
    cin >> t_case;

    for(int i=0 ; i<t_case ; i++){
        string command;
        cin >> command;

        int numOfArray;
        cin >> numOfArray;

        string array;
        cin >> array;

        array = array.substr(1,array.length()-2);

        string token;

        deque<int> intArray;

        if(numOfArray == 1){
            intArray.push_back(atoi(array.c_str()));
        }else if(numOfArray != 0){
            istringstream iss(array);
            while(getline(iss,token,',')){
                intArray.push_back(atoi(token.c_str()));
            }
        }

        bool isR = false;
        bool isOkay = true;

        for(int j=0 ; j<command.length() ; j++){
            if(command.at(j) == 'R'){
                isR = !isR;
            }else if(command.at(j) == 'D'){
                if(numOfArray==0){
                    cout << "error";
                    isOkay = false;
                    break;
                }else if(isR){
                    intArray.pop_back();
                    numOfArray--;
                }else{
                    intArray.pop_front();
                    numOfArray--;
                }
            }
        }

        if(!isR && isOkay){
            cout << "[";

            deque<int>::iterator iter;
            for(iter = intArray.begin();iter!=intArray.end();iter++){
                cout << *iter;
                if(iter != intArray.end()-1){
                    cout << ",";
                }
            }

            cout << "]";
        } else if(isR && isOkay){
            cout << "[";

            deque<int>::reverse_iterator iter;
            for(iter = intArray.rbegin() ; iter!=intArray.rend() ; iter++){
                cout << *iter;
                if (iter != intArray.rend()-1){
                    cout << ",";
                }
            }

            cout << "]";
        }
        cout << endl;
    }
    return 0;
}
