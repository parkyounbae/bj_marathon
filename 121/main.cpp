#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string notation2(int num) {
    int temp = num;
    string result = "";

    for(int i=2 ; i>=0 ; i--) {
        result += to_string(temp/(int)pow(2,i));
        temp = temp % (int)pow(2,i);
    }
    return result;
}

int main() {
    string num;
    cin >> num;

    if(num == "0") {
        cout << 0;
        return 0;
    }

    vector<char> result;

    for(int i=0 ; i<num.size() ; i++) {
        string temp = notation2((int)num.at(i)-48);
        for(int i=0 ; i<3 ; i++) {
            result.push_back(temp.at(i));
        }
    }

    while(result.front() == '0') {
        result.erase(result.begin());
    }

    for(int i=0 ; i<result.size() ; i++) {
        cout << result[i];
    }

    return 0;
}
