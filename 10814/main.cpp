#include <iostream>
using namespace std;

int age_tmp[1000001];
string name_temp[1000001];

void merge(int* age,string* name,int left,int right){
    int l_index = left;
    int mid = (left+right)/2;
    int n_index = left;
    int r_index = mid+1;

    while(l_index<=mid && r_index<=right){
        if(age[l_index]==age[r_index]){
            name_temp[n_index] = name[l_index];
            age_tmp[n_index++] = age[l_index++];
            //name_temp[n_index] = name[r_index];
            //age_tmp[n_index++] = age[r_index++];
        }else if(age[l_index] < age[r_index]){
            name_temp[n_index] = name[l_index];
            age_tmp[n_index++] = age[l_index++];
        }else if(age[l_index] > age[r_index]){
            name_temp[n_index] = name[r_index];
            age_tmp[n_index++] = age[r_index++];
        }
    }

    if(l_index<=mid){
        for(int i=l_index ; i<=mid ; i++){
            name_temp[n_index] = name[i];
            age_tmp[n_index++] = age[i];
        }
    }else if(r_index<=right){
        for(int i=r_index ; i<=right ; i++){
            name_temp[n_index] = name[i];
            age_tmp[n_index++] = age[i];
        }
    }

    for(int i=left ; i<=right ; i++){
        age[i] = age_tmp[i];
        name[i] = name_temp[i];
    }
}

void mergeSort(int* age, string* name, int left, int right){
    if(left==right)
        return;

    int mid = (left+right)/2;
    mergeSort(age,name,left,mid);
    mergeSort(age,name,mid+1,right);
    merge(age,name,left,right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    int age[n];
    string name[n];
    for(int i=0 ; i<n ; i++){
        cin >> age[i] >> name[i];
    }

    mergeSort(age,name,0,n-1);

    for(int i=0 ; i<n ; i++){
        cout << age[i] << " " << name[i] << '\n';
    }

    return 0;
}
