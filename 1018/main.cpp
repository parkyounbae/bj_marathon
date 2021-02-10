#include <iostream>
#include <vector>


using namespace std;

int main() {
    int m,n;
    cin>>m>>n;

    vector<string> arr;
    for(int i=0 ; i<m ; i++){
        string tmp;
        cin >> tmp;
        cin.clear();
        arr.push_back(tmp);
    }

    int result = 64;
    //char start;

    for(int i=0 ; i<=m-8 ; i++){
        for(int j=0 ; j<=n-8 ; j++){
            int tmp = 0;

            //start = 'W';//시작이 화이트라 가정하고
            for(int k=i ; k<i+8 ; k+=2){
                for(int l=j ; l<j+8 ; l+=2){
                    if(arr[k].at(l)!= 'W'){
                        tmp++;
                    }
                    if(arr[k].at(l+1)!='B'){
                        tmp++;
                    }
                    if(arr[k+1].at(l) != 'B'){
                        tmp++;
                    }
                    if(arr[k+1].at(l+1)!= 'W'){
                        tmp++;
                    }
                }
            }
            if(result > tmp){
                result = tmp;
            }
            //start = 'B';//시작이 화이트라 가정하고
            tmp = 0;
            for(int k=i ; k<i+8 ; k+=2){
                for(int l=j ; l<j+8 ; l+=2){
                    if(arr[k].at(l)!= 'B'){
                        tmp++;
                    }
                    if(arr[k].at(l+1)!='W'){
                        tmp++;
                    }
                    if(arr[k+1].at(l) != 'W'){
                        tmp++;
                    }
                    if(arr[k+1].at(l+1)!= 'B'){
                        tmp++;
                    }
                }
            }
            if(result > tmp){
                result = tmp;
            }
        }
    }

    cout << result << endl;
    return 0;
}
