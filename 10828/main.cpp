#include <iostream>

using namespace std;

int stack[10000];
int size_ = 0;

void push(int num,int* stack_){
    stack_[size_] = num;
    size_++;
}

int isEmpty(int* stack_){
    if(size_ == 0){
        return 1;
    }else{
        return 0;
    }
}

int pop(int* stack_){
    if(isEmpty(stack_)){
        return -1;
    }else{
        int tmp = stack_[size_-1];
        stack_[size_-1]=0;
        size_--;
        return tmp;
    }
}

int top(int* stack_){
    if(isEmpty(stack_)){
        return -1;
    }
    return stack_[size_-1];
}

int checkSize(int* stack_){
    return size_;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    for(int i=0 ; i<num ; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int tmp;
            cin >> tmp;
            push(tmp,stack);
        }else if(command == "top"){
            cout << top(stack) << endl;
        }else if(command == "pop"){
            cout << pop(stack) << endl;
        }else if(command == "empty"){
            cout << isEmpty(stack) << endl;
        }else if(command == "size"){
            cout << checkSize(stack) << endl;
        }
    }

    return 0;
}
