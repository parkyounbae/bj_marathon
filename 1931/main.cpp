#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    long long start;
    long long end;
}Meeting;

bool cmp(const Meeting &m1,const Meeting &m2){
    if(m1.end < m2.end){
        return true;
    }else if(m1.end == m2.end){
        return m1.start < m2.start;
    }else{
        return false;
    }
}

int main() {
    int N;
    cin >> N;
    Meeting meeting[N];

    for(int i=0 ; i<N ; i++){
        cin >> meeting[i].start >> meeting[i].end;
    }

    int index = 0;

    sort(meeting,meeting+N,cmp);

    int result = 1;
    for(int i=1 ; i<N ; i++){
        if(meeting[i].start >= meeting[index].end){
            index = i;
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
