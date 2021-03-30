#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    int arr[num];
    int sum = 0;
    int index = -1;

    for(int i=0 ; i<num ; i++){
        int tmp;
        cin >> tmp;

        if(tmp != 0){
            index++;
            arr[index] = tmp;
            sum += tmp;
        }else{
            sum-=arr[index];
            arr[index--] = 0;
        }
    }

    cout << sum << endl;

    return 0;
}
