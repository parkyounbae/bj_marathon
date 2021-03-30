#include <iostream>
#include <cstring>
using namespace std;

int main() {
    while(1){
        char input[101];
        cin.getline(input,101);

        if(strcmp(input,".")==0) break;

        int stack[101]; //1=( 2=) 3=[ 4=]

        int input_index = 0;
        int stack_index = 0;
        int result = 0;

        while(input[input_index] != '.'){

            if(input[input_index] == '('){
                stack[stack_index] = 1;
                stack_index++;
            }else if(input[input_index] == ')'){
                if(stack[stack_index-1] != 1){
                    result = -1;
                    //cout << "info A :" << endl;
                    break;
                }

                stack_index--;
                stack[stack_index] = 0;
            }else if(input[input_index] == '['){
                stack[stack_index] = 3;
                stack_index++;
            }else if(input[input_index] == ']'){
                if(stack[stack_index-1] != 3) {
                    result = -1;
                    //cout << "info B :" << endl;
                    break;
                }

                stack_index--;
                stack[stack_index] = 0;
            }

            input_index++;
        }

        if(stack_index!=0 || result==-1){
            //cout << "stackindex : " << stack_index << " result : " << result << endl;
            cout << "no" << endl;
        }else{
            cout << "yes" << endl;
        }
    }


    return 0;
}
