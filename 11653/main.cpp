#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
const int MAX = 10000000;
int minFac[MAX];

void makePrimeArr(){ //에라토스테네스의 채를 이용해 소수면 그대로 소수가 아니면 최소소인수 배열을 저장한다.
    minFac[0] = minFac[1] = -1; //일단 0과 1은 예외처리
    for(int i=2 ; i<=N ; i++){
        minFac[i] = i; //일단 모든 수를 소수처럼 표시를 해놓는다.
    }
    int sN = sqrt(N); //소수 판별할때 그냥 제곱근 사용... 그 안에서 다 나온다.
    for(int i=2 ; i<=sN ; i++){
        if(minFac[i]==i){ //같다는 것은 소수라는 뜻 ..... 소수가 아니라면 최소소인수로 바뀌었음
            for(int j=i ; j<=N ; j+=i){ //찾은 소수를 이용해 배수에 대해 다 소수가 아니라고 판별하자
                if(minFac[j]==j){ //그런데 이때 우리가 구하는 것은 최소소인수 이므로 이미 소수가 아닌것으로 판별된것은 패스
                    minFac[j] = i; //처음으로 소수의 배수를 만났다? 그건 최소소인수를 찾았다는 뜻
                }
            }
        }
    }

}

int main() {
    //정수 n이 주어졌을때 소인수분해를 해라
    cin >> N;
    makePrimeArr(); //이 함수를 통해 각 수의 최솟 소인수를 구한다.

    vector<int> result;

    int tmp = N;
    while(tmp > 1){
        result.push_back(minFac[tmp]); //일단 구하려는 수의 최소소인수를 벡터에 집어넣고
        tmp = tmp/minFac[tmp]; //노나버
    }

    sort(result.begin(),result.end());
    for(int i : result){
        cout << i << endl;
    }

    return 0;
}
