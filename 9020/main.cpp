#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> primeArr(int num){
    vector<int> arr;
    int* tmp = new int[num+1];

    tmp[0] = tmp[1] = -1;

    int sqrtNum = sqrt(num);
//에라토스테네스의 체를 이용해 범위에 해당하는 소수들 찾아서 벡터 반환
    for(int i=2 ; i<=sqrtNum ; i++){
        if(tmp[i]==0){
            for(int j=i*2 ; j<=num ; j=j+i){
                tmp[j] = -1;
            }
        }
    }

    for(int i=2 ; i<=num ; i++){
        if(tmp[i]==0){
            arr.push_back(i);
        }
    }
    return arr;
}

int main() {
    int t_case;
    cin >> t_case;
    vector<int> arr(t_case); //시험할 테스트 케이스만큼 정수배열
    vector< vector<int> > vecarr;

    for(int i=0 ; i<t_case ; i++){
        cin >> arr[i];
        vecarr.push_back(primeArr(arr[i]));
        cin.clear();
    } //입력받고 각 수에 해당하는 소수배열 벡터에 삽입

    for(int i=0 ; i<t_case ; i++){
        int gap=0;
        int tmp = arr[i]/2;

        for(int j=0 ; j<tmp ; j++){
            vector<int>::iterator it,it2;
            it = find(vecarr[i].begin(),vecarr[i].end(),tmp-gap);
            it2 = find(vecarr[i].begin(),vecarr[i].end(),tmp+gap);
            if(it!=vecarr[i].end() && it2!=vecarr[i].end())
                break;
            gap++;
        }

        cout << tmp-gap << " " << tmp+gap << endl;

    }

    return 0;
}
