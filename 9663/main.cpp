#include <iostream>
using namespace std;
int n;
int result = 0;
/*(cnt,num)
 (1,1) (2,1) (3,1) (4,1) ..
 (1,2) (2,2) (3,2) (4,2) ...
 (1,3) (2,3) (3,3) (4,3) ..
 (1,4) (2,4) (3,4) (4,4) ...
 */

bool isDiagonal(int num,int* visited,int cnt){
    //cnt번째 세로 줄 num번째 칸에 말을 놓으려는데 대각선에 겹치는게 있어??
    for(int i=1 ; i<cnt ; i++){
        if(abs(cnt-i) == abs(visited[i]-num) || visited[i]==num){
            return false;
        }
    }
    //cout << "(" << cnt << ", " << num << ")" << endl;
    return true;
}

void count(int now,int* visited,int cnt){
    visited[cnt] = now; //cnt번째 세로 줄, now번째 가로줄에 말놓
    if(cnt == n){
        result++;
        return;
    }

    for(int i=1 ; i<=n ; i++){
        if(i!=now && isDiagonal(i,visited,cnt+1)){
            visited[cnt+1] = i;
            count(i,visited,cnt+1);
            visited[cnt+1] = 0;
        }
    }
}


int main() {
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        int visited[16] = {0,};
        count(i,visited,1);
    }

    cout << result << endl;
    return 0;
}