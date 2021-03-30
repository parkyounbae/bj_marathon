#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int size;
    scanf("%d",&size);

    stack<int> s;
    vector<int> arr;

    for(int i=0 ; i<size ; i++){
        int temp;
        scanf("%d",&temp);
        arr.push_back(temp); //입력받은 수열을 벡터에 push
    }

    vector <int> ans(arr.size(), -1); //정답을 저장할 벡터를 생성함, 답이 없는 경우에는 -1이 출력되어야 하므로 -1로 출력

    for (int i = 0; i < arr.size(); i++) { //한바퀴 도는거니까 사이즈만큼 반복문
        while(!s.empty() && arr[s.top()] < arr[i]) { //조건 : 스택이 비어있지 않음 && 이전의 인덱스에 위치한 수 보다 현재에 위치한 수가 큼
            ans[s.top()] = arr[i]; //이전 인덱스의 답을 현재의 수로 바끔(현재의 수 == 이전 인덱스의 오큰수!)
            s.pop(); //해결되었으니까 pop
        }
        s.push(i); //비어있거나 해당하는수가 없다? 바로 push
    }

    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}
