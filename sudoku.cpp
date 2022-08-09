#include <iostream>
using namespace std;
Sudoku::Sudoku(){

}

Sudoku::Sudoku(int givenProblem[][9]){
    for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9; j++)
        {
            problem[i][j] = givenProblem[i][j];
        }
    }
}

void Sudoku::SudokuSolver(){
    int n = 0;
     for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(problem[i][j] == 0)
                n++;
        }
    }

    int ret = findSolution(n);
    if(ret != 0)
    {
        cout<<"solved!!"<<endl;
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
                int  solutioncount = 0 ; 
                for(int z = 1; z <= 9; z++ )
                {
                    problem[i][j] = z;
                    int ret = 0;
                    if(isValid(i,j))
                    {
                        ret = SudokuSolverHelper(n-1);
                    }
                    if(ret != 0)
                    {
                         solutioncount += ret;
                    }
                    if(z == 9 && solutioncount == 0)
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
                for(int z = 1; z <= 9; z++ )
                {
                    problem[i][j] = z;
                    int ret = 0;
                    if(isValid(i,j))
                    {
                        ret = findSolution(n-1);
                    }
                    if(ret != 0)
                    {
                         return ret;
                    }
                    if(z == 9)
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

void Sudoku::SudokuPrinter()
{
    for(int i = 0; i < 9 ; i ++)
    {
        for(int j = 0; j < 9 ; j ++)
        {
            cout<<problem[i][j] << " ";
        }

        cout<<endl;
    }
}
