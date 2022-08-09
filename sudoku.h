#pragma once

#include <iostream>
#include <vector>
using namespace std;
class Sudoku
{
    public:
        int problem[9][9];
        Sudoku();
        Sudoku(int [][9]);
        void SudokuSolver();
        void SudokuPrinter();
        int SudokuSolverHelper(int);
        int findSolution(int);
        bool isValid(int, int);
};

#include "sudoku.cpp"