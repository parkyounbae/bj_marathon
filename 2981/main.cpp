#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return a % b ? gcd(b, a%b) : b;
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    int arr[num];
    int result[501];
    int max_ = 0;

    for(int i=0 ; i<num ; i++){
        cin >> arr[i];
        if(max_<arr[i])
            max_ = arr[i];
    }

    sort(arr,arr+num);

    int includeM = arr[1] - arr[0];
    for(int i=2 ; i<num ; i++){
        includeM = gcd(includeM,arr[i]-arr[i-1]);
    }

    int count = 0;
    for (int i = 1; i*i <= includeM; i++)
        if (includeM%i == 0) {
            result[count++] = i;
            if (i != includeM / i) result[count++] = includeM / i;
        }

    sort(result, result + count);
    for (int i = 0; i < count; i++)
        if (result[i] != 1)
            cout << result[i] << " ";

    return 0;
}
