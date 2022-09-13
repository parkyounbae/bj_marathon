#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> arr;

long long numOfPieces(long long lengthToCut) {
    long long result = 0;
    int k=arr.size();
    for(int i=0 ; i<k ; i++) {
        result += arr.at(i)/lengthToCut;
    }
    // cout << "lengthTo cut : " << lengthToCut << ", result : " << result << endl;
    return result;
}

long long binary_upper_bound(int numOfPiece) {
    long long leftIndex = 0;
    long long rightIndex = arr.at(arr.size()-1);
    long long midIndex = (rightIndex + leftIndex)/2;

    while(leftIndex < rightIndex) {
        midIndex = (rightIndex + leftIndex)/2;
        if(numOfPiece <= numOfPieces(midIndex)) {
            leftIndex = midIndex+1;
            // cout << "left index changed : " << leftIndex << endl;
        } else {
            rightIndex = midIndex;
            // cout << "right index changed : " << rightIndex << endl;
        }
    }
    return rightIndex-1;
}

int main() {
    int K, N;
    cin >> K >> N;

    for(int i=0 ; i<K ; i++) {
        long long tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    cout << binary_upper_bound(N) << endl;

    return 0;
}
