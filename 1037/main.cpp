#include <iostream>

using namespace std;
int main() {
    int num;
    cin >> num;

    int max_ = 0;
    int min_ = 1000001;


    int arr[num];
    for(int i=0 ; i<num ; i++){
        cin >> arr[i];

        if(min_ > arr[i]){
            min_ = arr[i];
        }

        if(max_ < arr[i]){
            max_ = arr[i];
        }


    }

    cout << min_*max_ << endl;
    return 0;
}
