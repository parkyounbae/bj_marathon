#include <iostream>

using namespace std;

void printMove(int before,int after,int num){
    if(num == 1){
        printf("%d %d\n",before,after); //홀수면 시작할때 1이 3으로 가자
    }else{
        int tmp = 6-(before+after); //빈칸을 tmp로 정해놓

        printMove(before,tmp,num -1);
        printf("%d %d\n",before,after);
        printMove(tmp,after,num-1);
    };
}

//과정을 3단계로 나누어야 할듯!
//13
//12 ,13, 23
//13 12 32 ,13, 21 23 13
//(12 13 23) 12 31 32 12 ,13,23 21 31 23 12 13 23
int main() {
    int num;
    cin >> num;

    //1개 옮기기 : 1
    //2개 옯기기 : 3 = 1 + 1 + 1
    //3개 옯기기 : 7 = 3 + 1 + 3 위에 두칸 옮기고 3번째꺼 옮기고 먼저 옮겼던 두개 다시 이동
    //4개 옮기기 : 15 = 7 + 1 + 7 위에 3개 옮기고 4번째꺼 옮기고 먼저 옮겼던 3개 이동 .. 이런식 계속
    cout << (1<<num)-1 << endl;

    //탑을 옯길때 짝수냐 홀수냐애 따라 시작이 왼쪽 오른쪽 달라지는 듯

    printMove(1,3,num);

    return 0;
}
