#include <iostream>
using namespace std;
int tmp[1000000];

void merge(int* arr_,int left,int right){
    int mid = (left+right)/2;
    int l_index = left;
    int r_index = mid+1;
    int n_index = left;

    while(l_index <= mid && r_index <= right){
        if(arr_[l_index] > arr_[r_index]){
            tmp[n_index++] = arr_[r_index++];
        }else{
            tmp[n_index++] = arr_[l_index++];
        }
    }

    if(l_index>mid){
        for(int i=r_index ; i<=right ; i++){
            tmp[n_index++] = arr_[i];
        }
    }else{
        for(int i=l_index ; i<=mid ; i++){
            tmp[n_index++] = arr_[i];
        }
    }
    for(int i=left ; i<=right ; i++){
        arr_[i] = tmp[i];
    }
}

void mergeSort(int* arr_, int left, int right){
    if(right == left){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(arr_,left,mid);
    mergeSort(arr_,mid+1,right);
    merge(arr_,left,right);
}

int main() {
    int num;
    scanf("%d",&num);
    int* arr2 = new int[num];
    for(int i=0 ; i<num ; i++){
        scanf("%d",&arr2[i]);
    }

    mergeSort(arr2,0,num-1);

    for(int i=0 ; i<num ; i++){
        printf("%d\n",arr2[i]);
    }

    return 0;
}
