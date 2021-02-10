#include <iostream>
using namespace std;

int main() {
    int t_case;
    cin >> t_case;

    int* score = new int[t_case];
    int* arr = new int[t_case*2];
    for(int i=0 ; i<t_case*2 ; i+=2){
        cin >> arr[i] >> arr[i+1];
        score[i/2] = 1;
    }

    for(int i=0 ; i<t_case*2 ; i+=2){
        for(int j=0 ; j<t_case*2 ; j+=2){
            if(j!=i && arr[i]<arr[j] && arr[i+1]<arr[j+1]){
                score[i/2]++;
            }
        }
    }

    for(int i=0 ; i<t_case ; i++){
        cout << score[i] << " ";
    }



    return 0;
}
