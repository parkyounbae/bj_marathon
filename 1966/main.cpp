#include <iostream>
#include <queue>

using namespace std;

int findMax(queue<int> arr){
    int max_ = 0;
    for(int i=0 ; i<arr.size() ; i++){
        if(arr.front() > max_){
            max_ = arr.front();
        }

        arr.push(arr.front());
        arr.pop();
    }

    //cout << "max : " << max_ << endl; //todo

    return max_;
}

int main() {
    int t_case;
    cin >> t_case;

    for(int i=0 ; i<t_case ; i++){
        int num,index;
        cin >> num >> index;
        queue<int> importance;
        int standard; //기준이 되는 수

        for(int j=0 ; j<num ; j++){
            int tmp;
            cin >> tmp;
            if(j==index){
                standard = tmp;
            }
            importance.push(tmp);
        }

        int count = 0;
        int max_ = findMax(importance);

        while(standard<=max_){
            if(importance.front() == max_){
                importance.pop();
                count++;
                max_ = findMax(importance);

                if(index == 0){
                    break;
                } else{
                    index--;
                }
            }else{
                importance.push(importance.front());
                importance.pop();
                if(index == 0){
                    index = importance.size()-1;
                }else{
                    index--;
                }
            }

            //cout << "index : " << index << endl; //todo
        }

        cout << count << endl;

    }
    return 0;
}
