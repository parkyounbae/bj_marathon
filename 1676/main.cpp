#include <iostream>
#include <algorithm>

using namespace std;

int count2(int num){
    int count = 0;
    while(true){
        if(num%2 != 0){
            break;
        }else{
            count++;
            num = num/2;
        }
    }
    return count;
}

int count5(int num){
    int count = 0;
    while(true){
        if(num%5 != 0){
            break;
        }else{
            count++;
            num = num/5;
        }
    }
    return count;
}

int main() {
    int num;
    cin >> num;

    int numOf2 = 0;
    int numOf5 = 0;

    for(int i=1 ; i<=num ; i++){
        numOf2 += count2(i);
        numOf5 += count5(i);
    }

    cout << min(numOf2,numOf5) << endl;


    return 0;
}
