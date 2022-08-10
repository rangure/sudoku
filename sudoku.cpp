#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
using namespace std;
Sudoku::Sudoku(){
    for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9; j++)
        {
            problem[i][j] = 0;
        }
    }
    srand(time(0));
    int ret = findSolution(81);
    int toRemoveSize = 50;
    // int removeList[toRemoveSize];
    int removeCount = 0;
    for(int i = 0; i < toRemoveSize; i++)
    {
        int index = rand() % 81;
        // removeList[i] = x;
        int x,y;
        x = index / 9;
        y = index - x * 9;
        if(problem[x][y] == 0)
        {
            continue;
        }
        else
        {
            int oldValue = problem[x][y];
            problem[x][y] = 0;
            int numSolution = SudokuSolverHelper(removeCount + 1);
            if(numSolution == 1)
            {
                removeCount++;
            }
            else
            {
                problem[x][y] = oldValue;
            }
        }
    }
    int finalresult = SudokuSolverHelper(removeCount);
    cout << "there are " << finalresult << " solutions on the generated sudoku" <<endl;
    cout << removeCount << " numbers removed" <<endl;
    emptySlot = removeCount;
    memcpy((void*)problemOriginal, (void*)problem, 81*sizeof(int));
}

Sudoku::Sudoku(int givenProblem[][9]){
    emptySlot = 0;
    for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9; j++)
        {
            problem[i][j] = givenProblem[i][j];
            if(!givenProblem[i][j])
                emptySlot++ ;
        }
    }
}

void Sudoku::SudokuSolver(){
    int n = 0;
    srand(time(0));

     for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(problem[i][j] == 0)
                n++;
        }
    }
    cout << endl;
    int ret = findSolution(n);
    if(ret != 0)
    {
        cout<<"solved!!"<<endl;
        emptySlot = 0;
    }
    else
    {
        cout<<"cant find solution"<<endl;
    }
}

int Sudoku::SudokuSolverHelper(int n){
    if( n == 0) 
    {
        return 1;
    }
    for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9 ; j ++)
        {
            if(problem[i][j] == 0)
            {
                int solutioncount = 0 ; 

                for(int z = 0; z < 9; z++ )
                {
                    problem[i][j] = z + 1;
                    int ret = 0;
                    if(isValid(i,j))
                    {
                        ret = SudokuSolverHelper(n-1);
                    }
                    if(ret != 0)
                    {
                         solutioncount += ret;
                    }
                    if(z == 8 && solutioncount == 0)
                    {
                        problem[i][j] = 0;
                        return 0;
                    }
                }
                problem[i][j] = 0;
                return solutioncount;
            }
        }
    }

}
int Sudoku::findSolution(int n){
    if( n == 0) 
    {
        return 1;
    }
    for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9 ; j ++)
        {
            if(problem[i][j] == 0)
            {
                int randindex[9] = {0};
                
                for(int k = 0; k < 9; k++)
                {
                    int index = rand() % 9;
                    while(randindex[index % 9] != 0)
                    {
                        index++;
                    }
                    randindex[index % 9] = k + 1;
                }
                for(int z = 0; z < 9; z++ )
                {
                    problem[i][j] = randindex[z];
                    int ret = 0;
                    if(isValid(i,j))
                    {
                        ret = findSolution(n-1);
                    }
                    if(ret != 0)
                    {
                         return ret;
                    }
                    if(z == 8)
                    {
                        problem[i][j] = 0;
                        return 0;
                    }
                }
            }
        }
    }

}

bool Sudoku::isValid(int x, int y){
    for(int i = 0; i < 9 ; i ++)
    {
        if(i != y)
        {
            if(problem[x][i] == problem[x][y])
                return false;
        }
        if(i != x)
        {
            if(problem[i][y] == problem[x][y])
                return false;
        } 
        
    }
   
    int rowcell = x/3;
    int colcell = y/3;
    for(int i = 0 ; i <3; i ++)
    {
        for (int j = 0; j <3; j++)
        {
            if(rowcell*3 + i == x && colcell*3 + i == y)
                continue;
            if(problem[rowcell*3 + i][colcell*3 + i] == problem[x][y])
                return false;
        }
    }    
    return true;
}

void Sudoku::SudokuPrinter(int flag)
{

    for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9 ; j ++)
        {
            if(flag == 1)
            {
                cout<<problem[i][j] << " ";
            }
            else
            {
                cout<<problemOriginal[i][j] << " ";
            }
        }

        cout<<endl;
    }
}
bool Sudoku::couldChange(int x, int y){
    if(problemOriginal[x][y])
        return false;
    return true;
}

int Sudoku::getCurrentValue(int x, int y){
    return problem[x][y];
}
void Sudoku::changeValue(int x, int y, int z){
    problem[x][y] = z;
}
void Sudoku::reset(){
    memcpy((void*)problem, (void*)problemOriginal, 81*sizeof(int));
}
void Sudoku::decreaseEmptySlot(){
    emptySlot--;
}
int Sudoku::getEmptySlot(){
    return emptySlot;
}