#include <iostream>

using namespace std;

void quickSort2(int* arr, int left, int right){
    if(left >= right){
        return;
    }

    int pivot = arr[(left+right)/2];
    int r_tmp = right;

    int l_tmp = left;

    while(r_tmp >= l_tmp){
        while (pivot > arr[l_tmp]) {l_tmp++; }
        while (pivot < arr[r_tmp]) {r_tmp--; }
        if(l_tmp <= r_tmp){
            int tmp = arr[l_tmp];
            arr[l_tmp] = arr[r_tmp];
            arr[r_tmp] = tmp;

            l_tmp++;r_tmp--;
        }
    }
    if(left < r_tmp) quickSort2(arr,left,r_tmp);
    if(l_tmp<right) quickSort2(arr,l_tmp,right);
}


int main() {
    int t_case;
    scanf("%d",&t_case);
    int* arr = new int[t_case];
    for(int i=0 ; i<t_case ; i++){
        scanf("%d",&arr[i]);
    }

    //cout << "complete " << endl;

    quickSort2(arr,0,t_case-1);

    //cout << "complete2 " << endl;

    for(int i=0 ; i<t_case ; i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}
