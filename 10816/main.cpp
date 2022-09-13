#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
vector<int> arr_to_find;
int N;

/*
 중복된 친구이기 때문에 일반적인 이분 탐색이 아닌 upperbound 와 Lowerbound 를 통해 내가 찾는 수의 범위의 양 끝 인덱스를 반환해야 한다.
 */

int binary_upper_bound(int numToFind) {
    int leftIndex = 0;
    int rightIndex = arr.size();
    while(leftIndex < rightIndex) {
        int midIndex = (leftIndex + rightIndex)/2;
        if(numToFind >= arr.at(midIndex)) {
            leftIndex = midIndex+1;
        } else {
            rightIndex = midIndex;
        }
    }
    return rightIndex;
}

int binary_lower_bound(int numToFind) {
    int leftIndex = 0;
    int rightIndex = arr.size();
    while(leftIndex < rightIndex) {
        int midIndex = (leftIndex + rightIndex)/2;
        if (numToFind <= arr.at(midIndex)) {
            rightIndex = midIndex;
        } else {
            leftIndex = midIndex + 1;
        }
    }
    return leftIndex;
}

int main() {
    cin >> N;

    for(int i=0 ; i<N ; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    // -10 -10 2 3 3 6 7 10 10 10

    int M;
    cin >> M;

    for(int i=0 ; i<M ; i++) {
        int tmp;
        cin >> tmp;
        arr_to_find.push_back(tmp);
    }

    for(int i=0 ; i<M ; i++) {
        cout << (binary_upper_bound(arr_to_find.at(i)) - binary_lower_bound(arr_to_find.at(i))) << " ";
    }

    return 0;
}
