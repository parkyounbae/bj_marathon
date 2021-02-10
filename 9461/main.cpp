#include <iostream>
using namespace std;
long waveArr[101] = {0,1,1,1,2,2};
long wave(int num){
    if(waveArr[num]!=0){
        return waveArr[num];
    }else{
        waveArr[num] = wave(num-1) + wave(num-5);
        return waveArr[num];
    }
}

int main() {
    int num;
    scanf("%d",&num);

    int* arr= new int[num];
    for(int i=0 ; i<num ; i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0 ; i<num ; i++){
        printf("%ld\n",wave(arr[i]));
    }

    return 0;
}
