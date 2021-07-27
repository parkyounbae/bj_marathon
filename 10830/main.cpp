#include <iostream>

using namespace std;

int** origin;
int N;

//제곱한 뒤에 모듈러 하는 함수
int** multi(int** arr, int** arr2) {
    int** result = new int*[N];
    for(int i=0 ; i<N ; i++) {
        result[i] = new int[N];
    }

    for(int i=0 ; i<N ; i++) {
        for(int j=0 ; j<N ; j++) {
            for(int k=0 ; k<N ; k++) {
                result[i][j] += arr[i][k] * arr2[k][j];
                result[i][j] %= 1000;
            }
        }
    }

    return result;
}

//지수를 반으로 나눠주는 함수
int** pow(int** arr, long exp) {
    if (exp == 1) {
        return arr;
    }

    int** result = pow(arr,exp/2);

    result = multi(result,result);

    if(exp%2 != 0) {
        result = multi(result,origin);
    }

    return result;
}

int main() {
    long B;
    cin >> N >> B;

    origin = new int*[N];
    for(int i=0 ; i<N ; i++) {
        origin[i] = new int[N];
    }

    for(int i=0 ; i<N ; i++) {
        for(int j=0 ; j<N ; j++) {
            int temp;
            cin >> temp;
            origin[i][j] = temp%1000;
        }
    }

    origin = pow(origin,B);

    for(int i=0 ; i<N ; i++) {
        for(int j=0 ; j<N ; j++) {
            cout << origin[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
