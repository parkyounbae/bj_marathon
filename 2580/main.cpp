#include <iostream>
using namespace std;

int sudoku[9][9];
bool lowcheck[9][10] = {false,};
bool colcheck[9][10] = {false,};
bool sqcheck[9][10] = {false,};

void printSudoku(){
    for(auto & i : sudoku){
        printf("%d %d %d %d %d %d %d %d %d\n",i[0],i[1],i[2],i[3],i[4],i[5],i[6],i[7],i[8]);
    }
}

void solveProblem(int low,int col){
    if(low==9 && col==0){
        printSudoku();
        exit(0);
    }
    //checkZero(low,col);
    if(sudoku[low][col] != 0){
        if(col==8){
            solveProblem(low+1,0);
        }else{
            solveProblem(low,col+1);
        }
    }else{
        //0을 찾았을때

        for(int i=1 ; i<10 ; i++){
            if(!lowcheck[low][i] && !colcheck[col][i] && !sqcheck[((low/3)*3) + (col/3)][i]){
                sudoku[low][col] = i;
                lowcheck[low][i] = true;
                colcheck[col][i] = true;
                sqcheck[((low/3)*3) + (col/3)][i] = true;

                if(col==8){
                    solveProblem(low+1,0);
                }else{
                    solveProblem(low,col+1);
                }

                sudoku[low][col] = 0;
                lowcheck[low][i] = false;
                colcheck[col][i] = false;
                sqcheck[((low/3)*3) + (col/3)][i] = false;
            }
        }
    }
}

int main() {
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j]){
                lowcheck[i][sudoku[i][j]]=true;
                colcheck[j][sudoku[i][j]]= true;
                sqcheck[((i/3)*3) + (j/3)][sudoku[i][j]] = true;
            }
        }
    }

    solveProblem(0,0);

    return 0;
}

/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
 */