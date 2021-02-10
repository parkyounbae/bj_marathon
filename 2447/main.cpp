#include <iostream>

using namespace std;

void draw(int x,int y,int num){
    //한칸짜리들의 빈공간을 죄표로 표현하면 1,1 1,4 1,7 ... 이런식으로 나머지가 1일때이다.
    //9x9일대도 큰 빈칸을 보면 3,3 3,4 3,5 4,3 4,4 4,5 .. 이런식인데 이것도 3으로 나눈뒤 그 해의 3에대한 나머지가 1일때이다.
    if((x/num)%3==1 && (y/num)%3==1){
        cout << " ";
    }else{
        if(num/3 == 0){
            cout << "*";
        }else{
            draw(x,y,num/3);
        }
    }
}

int main() {
    int num;
    cin >> num;

    for(int i=0 ; i<num ; i++){
        for(int j=0 ; j<num ; j++){
            draw(i,j,num);
        }
        cout << '\n';
    }

    return 0;
}
