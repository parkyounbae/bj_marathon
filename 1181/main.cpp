#include <iostream>
using namespace std;

string temp[20001];

void merge(string* arr, int left, int right){
    int l_index = left;
    int mid = (left+right)/2;
    int r_index = mid+1;
    int n_index = left;

    while(l_index<=mid && r_index<=right){
        if(arr[l_index].size() < arr[r_index].size()){
            temp[n_index++] = arr[l_index++];
        }else if(arr[l_index].size() > arr[r_index].size()){
            temp[n_index++] = arr[r_index++];
        }else if(arr[l_index].size() == arr[r_index].size()){
            for(int i=0 ; i<=arr[l_index].size() ; i++){
                if(i==arr[l_index].size()){
                    temp[n_index++] = arr[r_index++];
                    temp[n_index++] = arr[l_index++];
                    break;
                }

                if(arr[l_index].at(i) < arr[r_index].at(i)){
                    temp[n_index++] = arr[l_index++];
                    break;
                }else if(arr[l_index].at(i) > arr[r_index].at(i)){
                    temp[n_index++] = arr[r_index++];
                    break;
                }
            }
        }
    }

    if(l_index <= mid){
        for(int i=l_index ; i<=mid ; i++){
            temp[n_index++] = arr[i];
        }
    }else if(r_index <= right){
        for(int i=r_index ; i<=right ; i++){
            temp[n_index++] = arr[i];
        }
    }

    for(int i=left ; i<=right ; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(string* arr, int left, int right){
    if(left == right){
        return;
    }

    int mid = (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,right);
}

int main() {
    int n;
    cin >> n;
    string arr[n];

    for(int i=0 ; i<n ; i++){
        string tmp;
        cin >> tmp;
        arr[i] = tmp;
    }



    mergeSort(arr,0,n-1);

    for(int i=0 ; i<n ; i++){
        if(i==n-1){
            cout << arr[i] << endl;
        }else if(arr[i].compare(arr[i+1])!=0){
            cout << arr[i] << endl;
        }
    }


    return 0;
}
