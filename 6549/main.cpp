#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll arr[100001], seg[400001];

ll init(int node, int start, int end) {
    if (start == end) return seg[node] = start; // 이건 끝까지 내려갔을때 실행되는 코드, 맨 밑의 노드들만 보면 배열 그대로가 담겨있다.
    int mid = start + end >> 1; // 중간 나누
    int a = init(node * 2, start, mid), b = init(node * 2 + 1, mid + 1, end); //중간 기점으로 재귀 돌
    if (arr[a] > arr[b]) return seg[node] = b; //자식도느 = 원래 배열의 내용, 부모 노드 = 원래 배열의 내용중 더 작은 값에 대한 인덱스를 저
    else return seg[node] = a;
}

ll find(int node, int start, int end, int left, int right) {
    if (start > right || end < left) return 0; //1e10장 // 범위 넘어가면 0 리턴
    if (left <= start && end <= right) return seg[node]; //범위 안에 있다면 값 리턴, 여기서 값은 인덱스


    // 예를 들어 첫벌째 찾고 그다음 루프일때 1~1 범위일때 이 구간 실행된다.
    // 우리가 원하는 구간은 1~1 구간이니까 그거 나올때까지 내려감
    int mid = start + end >> 1; //비트 연산자, 중간 나누
    int a = find(node * 2, start, mid, left, right), b = find(node * 2 + 1, mid + 1, end, left, right);
    // mid=4, a=find(2,1,4,1,1)-> mid=2 a=find(4,1,2,1,1) -> mid=1 a=find(8,1,1,1,1)=arr[8](1 of leaf) b=find(9,2,1,1,1)=arr[9] 이런식으로 해당 구까지 내려가서 조사함
    if (arr[a] > arr[b]) return b;
    else return a;
}

ll query(ll left, ll right) {
    if (left > right) return 0;
    int index = find(1, 1, n, left, right); //(1,1,n,1,n) - index=2 //find(1,1,7,1,1)
    ll ans = (right - left + 1) * arr[index]; //ans= 7*arr[2]
    ans = max(ans, query(left, index - 1)); //query(1,1)
    ans = max(ans, query(index + 1, right)); //query(3,7)
    return ans;
}

/*
 * query(3,7) ... index = find(1,1,7,3,7) ...
 * find(1,1,7,3,7) -> mid=4 a=find(2,1,4,3,7) .. mid=2 a=find(4,1,2,3,7) ... mid=2 a=find(8,1,2,3,7)=0 b=find(9,3,2,3,7)=0 return 0
 *                                                      b=find(5,3,4,3,7)=seg[5] (b가 더 작으므로 b에 해당하는값 진출
 *                          b=find(3,
 *                          이런식으로 해당하는 범위에 대한 최소값을 딱딱 찾아서 진출시킴
*/


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    arr[0] = 1e10;

    while (1) {
        cin >> n;
        if (!n) break;

        for (int i = 1; i <= n; i++) cin >> arr[i];

        init(1, 1, n);

        cout << query(1, n) << "\n";
    }
}

/*
 *         2
 *     2       5
 *   2   3   5   7
 *  1 2 3 4 5 6
 *  */