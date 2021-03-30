#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    //첫 번째 수는 무조건 가능이고 그 이후부터가 문제
    //제시 된 수보다 더 큰 수가 나오기 전에는 무조건 1씩 감소하면서 내려와야 한다. 4 -> 3 -> 2 -> 1 이 순으로...
    //만약 이미 2가 나온 뒤에 3이 나왔다고 가정하면 3-> 1 이 가능하다.
    int t_case;
    scanf("%d",&t_case);
    int check[t_case];

    vector<char> result;
    stack<int> num;

    for(int i=0 ; i<t_case ; i++){
        scanf("%d",&check[i]);
    }

    int index = 0;
    for(int i=1 ; i<=t_case ; i++){
        num.push(i);
        result.push_back('+');
        while(!num.empty() && num.top()==check[index]){
            num.pop();
            result.push_back('-');
            index++;
        }
    }

    if(!num.empty()) printf("NO\n");
    else {
        for(int i=0 ; i<result.size() ; i++){
            printf("%c\n",result[i]);
        }
    }


    return 0;
}
