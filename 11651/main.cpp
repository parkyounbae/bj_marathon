#include <iostream>
using namespace std;

int tmparr_x[100001];
int tmparr_y[100001];

void merge(int* x,int* y,int left,int right){
    int l_index = left;
    int mid = (left+right)/2;
    int r_index = mid+1;
    int n_index = left;

    while(l_index <= mid && r_index<=right){
        if(x[l_index] < x[r_index]){
            tmparr_x[n_index] = x[l_index];
            tmparr_y[n_index] = y[l_index];
            n_index++; l_index++;
        }else if(x[l_index] > x[r_index]){
            tmparr_x[n_index] = x[r_index];
            tmparr_y[n_index] = y[r_index];
            n_index++; r_index++;
        }else if(x[l_index] == x[r_index]){
            if(y[l_index] > y[r_index]){
                tmparr_x[n_index] = x[r_index];
                tmparr_y[n_index] = y[r_index];
                n_index++; r_index++;
            }else{
                tmparr_x[n_index] = x[l_index];
                tmparr_y[n_index] = y[l_index];
                n_index++; l_index++;
            }
        }
    }

    if(l_index <= mid){
        for(int i=l_index ; i<=mid ; i++){
            tmparr_x[n_index] = x[i];
            tmparr_y[n_index] = y[i];
            n_index++;
        }
    }else{
        for(int i=r_index ; i<=right ; i++){
            tmparr_x[n_index] = x[i];
            tmparr_y[n_index] = y[i];
            n_index++;
        }
    }

    for(int i=left ; i<=right ; i++){
        x[i] = tmparr_x[i];
        y[i] = tmparr_y[i];
    }



}

void mergeSort(int* x,int* y,int left,int right){
    if(left == right){
        return;
    }

    int mid = (left+right)/2;
    mergeSort(x,y,mid+1,right);
    mergeSort(x,y,left,mid);
    merge(x,y,left,right);
}

int main() {
    int num;
    scanf("%d",&num);
    int* x = new int[num];
    int* y = new int[num];

    for(int i=0 ; i<num ; i++){
        scanf("%d %d",&x[i],&y[i]);
    }

    mergeSort(y,x,0,num-1);

    for(int i=0 ; i<num ; i++){
        printf("%d %d\n",x[i],y[i]);
    }


    return 0;
}
