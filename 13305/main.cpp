#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    long long distance[num-1];
    long long price[num];
    for(int i=0 ; i<num-1 ; i++){
        cin >> distance[i];
    }
    for(int i=0 ; i<num ; i++){
        cin >> price[i];
    }

    //한 도시씩 지나가면서 기름을 구매했던 도시와 도착한 도시의 기름값을 비교한 뒤 더 작은것을 선택한다.
    long long currentPrice = price[0];
    long long accumulatePrice = 0;

    for(int i = 0 ; i<num-1 ; i++){
        if(currentPrice >= price[i]){
            currentPrice = price[i];
        }

        accumulatePrice += currentPrice*distance[i];
    }

    cout << accumulatePrice << endl;
}
