#include <iostream>

using namespace std;

int main() {
    int t_case; //각각 예시의 수, 호텔의 층, 호텔의 너비

    cin >> t_case;

    int* h = new int[t_case];
    int* w = new int[t_case];
    int* n = new int[t_case];

    for(int i=0 ; i<t_case ; i++){
        cin >> h[i] >> w[i] >> n[i];
    }

    for(int i=0 ; i<t_case ; i++){

        //층은 나머지 호수는 나눈 값으로
        int floor = n[i]%h[i];
        int nth = n[i]/h[i]+1;
        if(floor == 0){ //딱 떨어질때 결과값에 대한 수정이 조금 필요해
            floor = h[i];
            nth --;
        }
        if(nth <10){
            cout << floor << "0" << nth << endl;
        }else{
            cout << floor << nth << endl;
        }
    }

    return 0;
}
