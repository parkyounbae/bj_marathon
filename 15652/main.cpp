#include <iostream>
using namespace std;

int n,m;
int arr[9] = {0,};

void dfs(int num,int cnt){
    if(cnt == m){
        for(int i=0 ; i<cnt ; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=num ; i<=n ; i++){
        arr[cnt] = i;
        dfs(arr[cnt],cnt+1);
    }
}

int main() {
    cin >> n >> m;
    dfs(1,0);
    return 0;
}
