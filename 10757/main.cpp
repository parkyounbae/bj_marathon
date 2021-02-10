#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    //long long 을 벗어난 수 더하기.... 받을수 있는 형식이 없으므로 문자열로 받아버리자
    string a,b;
    cin >> a >> b;

    int largeSize = max(a.size(),b.size());
    list<int> arr; //수를 쪼개서 더하면서 앞에다가 넣어야하는데 벡터가 편할듯

    int a_index = a.size()-1;
    int b_index = b.size()-1; //두 수가 자릿수가 다를경우 뒤에서 부터 더해야 하는데 어디인지 알수가 없으니까 인덱스 해놓고 반복문 돌면서 뒤에서부터 돌 예정
    int isOverTen = 0;
    for(int i=0 ; i<=largeSize ; i++){
        if(a_index-i >= 0 && b_index-i >= 0){
            //둘 다 0보다 크다? 아직 두개를 더해야 함!
            int tmp = (a.at(a_index-i)-'0') + (b.at(b_index-i)-'0');
            if(isOverTen==1){
                tmp++;
            }
            if(tmp > 9){
                isOverTen = 1;
                tmp = tmp - 10;
            }else{
                isOverTen = 0;
            }
            arr.push_front(tmp);
        }else if(a_index-i >= 0){
            int tmp = a.at(a_index-i)-'0';
            if(isOverTen==1){
                tmp++;
            }

            if(tmp>9){
                tmp = tmp - 10;
                isOverTen = 1;
            }else{
                isOverTen = 0;
            }

            arr.push_front(tmp);
        }else if(b_index-i >= 0){
            int tmp = b.at(b_index-i)-'0';
            if(isOverTen==1){
                tmp++;
            }

            if(tmp>9){
                tmp = tmp - 10;
                isOverTen = 1;
            }else{
                isOverTen = 0;
            }

            arr.push_front(tmp);
        }else{
            if(isOverTen==1){
                arr.push_front(1);
            }
        }
    }

    list<int>::iterator iter;

    for(iter = arr.begin() ; iter!=arr.end();iter++){
        cout << *iter;
    }


    return 0;
}
