#include <iostream>

using namespace std;

//이동시에 전에 이동한 거리의 +1 -1 0 만큼만 이동가능
//안전을 위해 무조건 도착 직전의 이동거리는 1
//최소한의 작동 횟수를 구하자
//1씩 거리를 늘리다가 중간부터 이동거리를 줄인다. -> 마지막에 1만큼 이동가능하게

int main() {
    int t_case;
    cin >> t_case;

    int* result = new int[t_case];

    for(int count=0 ; count<t_case ; count++){
        int x,y;
        cin >> x >> y;
        int dis = y-x; //이동할 거리
        int index = 1;

        while(dis >= index){
            if(dis >= index*2){
                result[count] += 2;
                dis = dis - index*2;
                index++;
            }else{
                dis = dis-index;
                result[count]++;
            }
        }

        if(dis != 0){
            result[count]++;
        }
    }

    for(int i=0 ; i<t_case ; i++){
        cout << result[i] << endl;
    }
}
