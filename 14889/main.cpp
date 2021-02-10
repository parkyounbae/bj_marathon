#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int statarr[21][21];
int gapmin = 100;
int num;
//bool visited[21] = {false,};
vector<int> startArr;
vector<int> linkTeam;

void calc( int cnt){
    if(cnt == num+1) {

        if(startArr.size()==num/2 && linkTeam.size()==num/2){
            int startPoint = 0;
            int linkPoint = 0;


/*
       for(int i=1 ; i<=num ; i++){
           if(!visited[i]){
               linkTeam.push_back(i);
           }
       }
*/
            for(int i=0 ; i<num/2 ; i++){
                for(int j=i+1 ; j<num/2 ; j++){
                    if(i==j)continue;
                    startPoint += statarr[startArr[i]][startArr[j]];
                    startPoint += statarr[startArr[j]][startArr[i]];

                    linkPoint += statarr[linkTeam[i]][linkTeam[j]];
                    linkPoint += statarr[linkTeam[j]][linkTeam[i]];
                }
            }

            if(abs(startPoint - linkPoint) < gapmin){
                gapmin = abs(startPoint - linkPoint);
            }
       }

        return;
    }

    startArr.push_back(cnt);
    calc(cnt+1);
    startArr.pop_back();

    linkTeam.push_back(cnt);
    calc(cnt+1);
    linkTeam.pop_back();



    /*
    for(int i=index ; i<=num ; i++){
        if(!visited[i]){
            visited[i] = true;
            arr.push_back(i);

            calc(arr,cnt+1,index+1);

            visited[i] = false;
            arr.pop_back();
        }
    }

     */

}

int main() {
    cin >> num;

    for(int i=1 ; i<=num ; i++){
        for(int j=1 ; j<=num ; j++){
            //cin >> statarr[i][j];
            scanf("%d",&statarr[i][j]);
        }
    }
    //startArr.push_back(1);
    //visited[1] = true;
    calc(1);

    printf("%d",gapmin);

    return 0;
}