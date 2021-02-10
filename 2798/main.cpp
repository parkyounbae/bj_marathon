#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int cardNum,num;
    cin >> cardNum >> num;

    int* arr = new int[cardNum];
    for(int i=0 ; i<cardNum ; i++){
        cin >> arr[i];
    }

    int gap = 1000000;
    int result;

    for(int i=0 ; i<cardNum-2 ; i++){
        for(int j=i+1 ; j<cardNum-1 ; j++){
            for(int k=j+1 ; k<cardNum ; k++){
                if(arr[i]+arr[j]+arr[k]<=num && num-(arr[i]+arr[j]+arr[k])<=gap){
                    result = arr[i]+arr[j]+arr[k];
                    gap = num-(arr[i]+arr[j]+arr[k]);
                }
            }
        }
    }
    cout << result << endl;

    return 0;
}
