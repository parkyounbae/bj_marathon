#include <iostream>
using namespace std;
int main() {
    int t_case;
    cin >> t_case;
    cin.clear();

    for(int i=0 ; i<t_case ; i++){
        int x1,y1,r1,x2,y2,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        //scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        //cin.clear();
        int disS = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

        int biggerR;
        if(r1 >= r2){
            biggerR = r1*r1;
        }else{
            biggerR = r2*r2;
        }

        if(x1==x2 && y1==y2 && r1==r2){
            cout << -1 << endl;
        }else if((r1+r2)*(r1+r2) == disS || (r1-r2)*(r1-r2) == disS){
            cout << 1 << endl;
        }else if((r1+r2)*(r1+r2) < disS && biggerR<disS){
            cout << 0 << endl;
        }else if((r1-r2)*(r1-r2) > disS && biggerR>disS){
            cout << 0 << endl;
        }else{
            cout << 2 << endl;
        }

    }




    return 0;
}
