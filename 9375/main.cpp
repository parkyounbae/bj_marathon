#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t_case;
    cin >> t_case;

    for(int i=0 ; i<t_case ; i++){
        int num;
        cin >> num; //옷 갯수 입력받음
        vector<string> arr; //옷 종류를 기록
        int resultArr[num]; //각 종류마다 갯수 저

        for(int j=0 ; j<num ; j++){
            resultArr[j] = 0;
        }

        string trash,tmp;

        for(int j=0 ; j<num ; j++){
            cin >> trash >> tmp; //옷 이름이랑 종류 저장.. 근데 이름 노필요

            vector<string>::iterator iter;
            iter = find(arr.begin(),arr.end(),tmp); //내가 입력받은 옷 종류가 이미 있는 종류인지 확인
            if(iter == arr.end()){ //없다면...
                arr.push_back(tmp); //뒤에 문자열 추가
                resultArr[arr.size()-1]++; //방금 추가한 옷 종류에 대한 수 추가
                //cout <<"can not find " << tmp << " : " << resultArr[arr.size()-1] << endl;
            }else{
                for(int k=0 ; k<arr.size() ; k++){
                    if(arr[k]==tmp){
                        resultArr[k]++;
                        //cout << "found " << tmp << " : " << resultArr[k]; //todo
                        break;
                    }
                }
            }
        }

        int result = 1;
        for(int j=0 ; j<arr.size() ; j++){
            result = result*(resultArr[j]+1);
            //cout << " test:" <<resultArr[j]; //todo
        }
        //cout << endl; //todo
        cout << result-1 << endl;

    }

    return 0;
}
