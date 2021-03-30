#include <iostream>

using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    int index = 0;

    int value[N];
    for(int i=0 ; i<N ; i++){
        cin >> value[i];
        if(value[i] <= K){
            index = i;
        }
    }

    int sum = 0 ,result = 0;
    while(sum!=K && index>=0){
        while(sum+value[index] <= K){
            sum += value[index];
            result++;
            //cout << value[index] <<" is added at " << result << endl; //todo
        }
        index--;
    }

    cout << result << endl;

    return 0;
}
