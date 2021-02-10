#include <iostream>

using namespace std;

void isRect(int a,int b,int c){
    if(a>b && a>c){
        if(a*a == b*b + c*c){
            cout << "right" << endl;
        }else{
            cout << "wrong" << endl;
        }
    }else if(b>a && b>c){
        if(b*b == a*a + c*c){
            cout << "right" << endl;
        }else{
            cout << "wrong" << endl;
        }
    }else if(c>a && c>b){
        if(c*c == a*a + b*b){
            cout << "right" << endl;
        }else{
            cout << "wrong" << endl;
        }
    }else{
        cout << "wrong" << endl;
    }
}

int main() {

    while(1){
        int a,b,c;
        cin >> a >> b >>c;
        if(a==0){
            break;
        }
        isRect(a,b,c);
    }
    return 0;
}
