#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int plusString(string plustmp){
    //cout << "+>>" << plustmp << endl;
    int pos = plustmp.find('+');
    int sum = 0;
    string tmpstring = plustmp;
    if(pos == string::npos){
        sum = atoi(plustmp.c_str());
    }else{
        while (pos != string::npos){
            string tmp = tmpstring.substr(0,pos);
            sum += atoi(tmp.c_str());

            tmpstring = tmpstring.substr(pos+1,tmpstring.size());
            if(tmpstring.find('+') == string::npos){
                sum+= atoi(tmpstring.c_str());
                break;
            }else{
                pos = tmpstring.find('+');
            }
        }
    }

    return sum;
}

int main() {
    string arr;
    cin >> arr;
    vector<int> num;
    int index = arr.find('-');
    if(index == string::npos){
        num.push_back(plusString(arr)) ; //-가 없을 경우 +만 있거나 그냥 숫자만 들어온 경우이므로 플러스 함수 써서 해결
    }else{
        while(index != string::npos){
            string tmp = arr.substr(0,index);
            //cout << "tmp>>" << tmp << endl;
            num.push_back(plusString(tmp));

            arr = arr.substr(index+1,arr.size());
            if(arr.find('-')==string::npos){
                num.push_back(plusString(arr));
                break;
            }else{
                index = arr.find('-');
            }
        }
    }

    int result = num[0];
    for(int i=1 ; i<num.size() ; i++){
        result -= num[i];
    }

    cout << result << endl;
}
