#include <iostream>
#include <stdio.h>
#include <vector>
#include "sudoku.h"
using namespace std;
int main()
{
    int answer[9][9] = 
    {
        {9,3,1,6,2,5,4,7,8},
        {5,6,4,8,7,3,2,1,9},
        {7,8,2,4,1,9,5,6,3},
        {1,4,3,2,9,6,8,5,7},
        {8,2,9,3,5,7,6,4,1},
        {6,7,5,1,8,4,3,9,2},
        {4,9,6,7,3,8,1,2,5},
        {2,5,8,9,4,1,7,3,6},
        {3,1,7,5,6,2,9,8,4}
    };
    int test[9][9] = 
    {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };
    char flag;
    while(1)
    {
        cout << "Press 1 to play, Press 2 to solve" << endl;
        cin >> flag;
        if(flag == '1' || flag == '2')
        {
            break;
        }
        cout << "Invalid input, try again" << endl;
    }
    if(flag == '1')
    {
        Sudoku s;
        
        while(1)
        {    
            cout<< "here is your sudoku" <<endl;    
            s.SudokuPrinter(1);
            cout<< "which slot and what number do you want to fill?(row, col, num) input 0,0,0 to reset sudoku" <<endl;
            int row, col, num;
            int ret = scanf("%d, %d, %d", &row, &col, &num);
            if (ret == 3 && !num && !row && !col)
            {
                cout << "Reseting..." <<endl;
                s.reset();
                continue;
            }

            if(ret != 3 || num <1 || num >9 || row < 0 || row > 9 || col <0 || col > 9)
            {
                cout << "Invalid input, try again" <<  endl;
                while(getchar() != '\n');
                continue;
            }

            if(!s.couldChange(row, col))
            {
                cout <<"Invalid position, cant change the problem" << endl;
                continue;    
            }
            int oldValue = s.getCurrentValue(row,col);
            s.changeValue(row,col,num);
            if( !s.isValid(row, col))
            {
                cout << num << " does not comply with sudoku rules at position "<< row << " " << col <<", try again" << endl;
                s.changeValue(row, col, oldValue);
                continue;
            }
            s.decreaseEmptySlot();
            int slotNum = s.getEmptySlot();
            if(slotNum == 0)
            {
                cout <<"Congratulations! you successfully solved the puzzle!" << endl;
                cout << "Solution :" << endl;
                s.SudokuPrinter(1);
                break;
            }

        }

    }
    // s.SudokuPrinter(1);
    // s.SudokuPrinter(0);
    // // int x ,y ,z;
    // // cin >> x;
    // // cin >> y;
    // // cin >> z;
    // // s.problem[x][y] = z;
    // // cout << endl;
    // // s.SudokuPrinter();
    // // cout << s.isValid(x,y) << endl;
    // s.SudokuSolver();
    // s.SudokuPrinter(1);
    return 0;
}