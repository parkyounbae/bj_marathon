#include <iostream>
#include <string>
using namespace std;
int main() {

    int num;
    cin >> num;
    int result,count=0;
    int start = 665;

    while (count<num){
        string tmp = to_string(start);
        if(tmp.find("666")!= string::npos ){
            count++;
            result = start;
        }
        start++;
    }

    cout << result << endl;

    return 0;
}
