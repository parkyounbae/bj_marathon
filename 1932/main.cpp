#include <iostream>
#include <algorithm>
using namespace std;

int t_case = 0;
int triangle[500][500];
int memo[500][500];

void calc(int cnt,int index){
    if(cnt == t_case){
        return;
    }else if(index == 0){
        memo[cnt][index] = memo[cnt-1][index] + triangle[cnt][index];
        calc(cnt,index+1);
    }else if(index == cnt){
        memo[cnt][index] = memo[cnt-1][index-1] + triangle[cnt][index];
        calc(cnt+1,0);
    }else{
        memo[cnt][index] = max(memo[cnt-1][index],memo[cnt-1][index-1]) + triangle[cnt][index];
        calc(cnt,index+1);
    }
}

int main() {
    cin >> t_case;

    for(int i=0 ; i<t_case ; i++){
        for(int j=0 ; j<=i ; j++){
            scanf("%d",&triangle[i][j]);
        }
    }
    memo[0][0] = triangle[0][0];
    calc(1,0);

    int max=0;
    for(int i=0 ; i<t_case ; i++){
        if(max < memo[t_case-1][i]){
            max = memo[t_case-1][i];
        }
    }

    printf("%d\n",max);

}
