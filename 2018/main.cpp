#include <iostream>
#include <cmath>
using namespace std;

int countArr[8001];

int mid(int num){
    int index = 0;

    for(int i=0 ; i<8001 ; i++){
        index += countArr[i];
        if(index >= num/2+1){
            return i-4000;
        }
    }
}

int mode(){
    int max = 0;
    int result = 0;


    int tmp[8001];
    int index = 0;

    for(int i=0 ; i<8001 ; i++){
        if(countArr[i] > max){
            tmp[0] = i-4000;
            max = countArr[i];

            for(int i=1 ; i<index ; i++){
                tmp[i] = 0;
            }
            index = 1;

        }else if(countArr[i] == max){
            tmp[index] = i-4000;
            index++;
        }
    }

    if(index == 1){
        return tmp[0];
    }else{
        return tmp[1];
    }


}

int range(){
    int first, last = 0;

    for(int i=0 ; i<8001 ; i++){
        if(countArr[i]!=0){
            first = i-4000;
            break;
        }
    }

    for(int i=8000 ; i>=0 ; i--){
        if(countArr[i]!=0){
            last = i-4000;
            break;
        }
    }


    return last-first;
}

int main() {

    //[0] = -4000, [4000]=0, [8000]=4000
    int num=0,sum=0;
    scanf("%d",&num);

    for(int i=0 ; i<num ; i++){
        int tmp_;
        scanf("%d",&tmp_);
        countArr[tmp_+4000]++;
        sum += tmp_;
    }

    //1.산술평균
    double sansul = (double)sum/(double)num;
    cout << round(sansul) << endl;
    //2.중앙값
    cout << mid(num) << endl;

    //3.최빈값
    cout << mode() << endl;

    //4.범위
    cout << range() << endl;



    return 0;
}
