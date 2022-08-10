#pragma once

class Sudoku
{
    public:
        int problem[9][9];
        int problemOriginal[9][9];
        int emptySlot;
        Sudoku();
        Sudoku(int [][9]); 
        void SudokuSolver();
        void SudokuPrinter(int);
        int SudokuSolverHelper(int);
        int findSolution(int);
        bool isValid(int, int);
        bool couldChange(int, int);
        void changeValue(int, int, int);
        int getCurrentValue(int, int);
        void reset();
        void decreaseEmptySlot();
        int getEmptySlot();

};

#include "sudoku.cpp"