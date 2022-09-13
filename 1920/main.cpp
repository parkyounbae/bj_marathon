#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;

bool find(int numToFind, int left, int right) {

    if(right < left) {
        return false;
    }

    int mid = (left + right)/2;

    if (vec.at(mid) > numToFind) {
        return find(numToFind,left,mid-1);
    } else if(vec.at(mid) < numToFind){
        return find(numToFind,mid+1,right);
    } else {
        return vec.at(mid) == numToFind;
    }
}

int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0 ; i<n ; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(),vec.end());

    int nToFind;
    cin >> nToFind;
    for(int i=0 ; i<nToFind ; i++) {
        int tmp;
        cin >> tmp;
        cout << find(tmp,0,n-1) << '\n';
    }

    return 0;
}
