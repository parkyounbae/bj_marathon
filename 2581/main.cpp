#include <iostream>
#include <vector>

using namespace std;

int isPrime(int num){
    //소수 고려할사항 1,2 주목!
    if(num ==1){
        return 0;
    }else if(num == 2){
        return 1;
    }

    for(int i=2;i<num;i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main() {
    int m,n, result = 0;
    cin >> m >> n;
    vector<int> arr;

    for(int i=m ; i<=n ; i++){
        if(isPrime(i)==1){
            arr.push_back(i);
            result += i;
        }
    }

    if(arr.empty()){
       cout << "-1" << endl;
    }else{
        cout << result << endl << arr[0] << endl;
    }

    return 0;
}
