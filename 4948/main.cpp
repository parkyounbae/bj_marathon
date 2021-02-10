#include <iostream>
#include <vector>
using namespace std;

int isPrime(int num){
    if(num == 1){
        return 0;
    }
    if(num == 2){
        return 1;
    }

    for(int i=2 ; i*i<=num ; i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}
int main() {
    int n = 1;
    vector<int> arr;

    while(n!=0){
        cin >> n;
        int count = 0;
        for(int i=n+1 ; i<=2*n ; i++){
            if(isPrime(i)==1){
                count++;
            }
        }
        arr.push_back(count);
    }

    for(int i=0 ; i<arr.size()-1 ; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
