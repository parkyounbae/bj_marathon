#include <iostream>

using namespace std;

int main() {

    int t_case;
    cin >> t_case;

    int* k = new int[t_case];
    int* n = new int[t_case];
    int* result = new int[t_case];

    for(int i=0 ; i<t_case ; i++){
        cin >> k[i] >> n[i];
        int* arr = new int[n[i]];
        for(int j=0 ; j<n[i] ; j++){
            arr[j] = j+1;
        }

        for(int j=1 ; j<=k[i] ; j++){
            for(int l=n[i]-1 ; l>=0 ; l--){
                int tmp = 0;
                for(int m=0 ; m<=l ; m++){
                    tmp = tmp + arr[m];
                }
                arr[l] = tmp;
            }
        }
        result[i] = arr[n[i]-1];
        delete[] arr;
    }

    for(int i=0 ; i<t_case ; i++){
        cout << result[i] << endl;
    }

    delete[] k;delete[] n; delete[] result;
}
