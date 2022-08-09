#include <istream>
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
    while(0)
    {
        cout << "Press 1 to play, Press 2 to solve" << endl;
        cin >> flag;
        if(flag == '1' || flag == '2')
        {
            break;
        }
        cout << "Invalid input, try again" << endl;
    }

    Sudoku s;
    s.SudokuPrinter();
    // int x ,y ,z;
    // cin >> x;
    // cin >> y;
    // cin >> z;
    // s.problem[x][y] = z;
    // cout << endl;
    // s.SudokuPrinter();
    // cout << s.isValid(x,y) << endl;
    s.SudokuSolver();
    s.SudokuPrinter();
    return 0;
}