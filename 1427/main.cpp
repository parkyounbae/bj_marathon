#include <iostream>
#include <string>

using namespace std;
int main() {
    string num;
    cin >> num;
    for(int i=0 ; i<num.size()-1 ; i++){
        for(int j=i+1 ; j<num.size() ; j++){
            if(num.at(i) < num.at(j)){
                char tmp = num.at(i);
                num.at(i) = num.at(j);
                num.at(j) = tmp;
            }
        }
    }

    cout << num << endl;
    return 0;
}
