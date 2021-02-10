#include <iostream>
using namespace std;

typedef struct {
    int zero_= 0;
    int one_ = 0;
    bool visited = false;
} Memo;
Memo arr[41];

Memo MemoAdd(Memo a,Memo b){
    Memo tmp;
    tmp.one_ = a.one_ + b.one_;
    tmp.zero_ = a.zero_ + b.zero_;
    tmp.visited = true;
    return tmp;
}

Memo fibonacci(int num){
    if(num == 0){
        arr[num].zero_ = 1;
        arr[num].visited = true;
        return arr[num];
    }else if(num ==1){
        arr[num].one_ = 1;
        arr[num].visited = true;
        return arr[num];
    }else{
        if(arr[num].visited){
            return arr[num];
        }
        arr[num] = MemoAdd(fibonacci(num-1),fibonacci(num-2));
        return arr[num];
    }
}
//f2 f1
//f2 = f1 + f0 ( 1,1,true)
//f3 = f2 + f2 (1,2,true)
//f4 = f3 + f2 (2,3,true)
//f5 = f4 + f3 (3,5,true)

int main() {
    int t_case;
    cin >> t_case;
    Memo* result_arr = new Memo[t_case];

    for(int i=0 ; i<t_case ; i++){
        int tmp;
        cin >> tmp;
        result_arr[i] = fibonacci(tmp);
    }

    for(int i=0 ; i<t_case ; i++){
        cout << result_arr[i].zero_ << " " << result_arr[i].one_ << endl;
    }


    return 0;
}
