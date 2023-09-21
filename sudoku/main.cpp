#include "Sudoku.h"
using namespace std;

int main()
{
    srand(time(NULL));

    Sudoku sudoku;

    int type;

    cout << "Type 1 to transform the sampleboard then generate a sudoku problem!\n";
    cout << "Type 2 to solve the sudoku problem!\n";

    while (cin >> type)
    {
        if (type == 1)
        {
            cout << "The original Board is: \n";

            sudoku.PrintBoard(sudoku.GetSampleBoard());
            sudoku.Transform();

            cout << "The Transformed Board is: \n";
            sudoku.PrintBoard(sudoku.GetTransformBoard());

            sudoku.Generate();

            cout << "The generated sudoku problem is: \n";
            sudoku.PrintBoard(sudoku.GetOutputBoard());

            break;
        }
        else if (type == 2)
        {
            cout << "The problem is : \n";
            sudoku.PrintBoard(sudoku.GetProblemBoard());
            cout << "The solution is : \n";

            if (sudoku.Solve(sudoku.GetSolvedBoard()) && sudoku.CheckUniqueness())
                sudoku.PrintBoard(sudoku.GetSolvedBoard());
            else if (sudoku.Solve(sudoku.GetSolvedBoard()) && !sudoku.CheckUniqueness())
                cout << "It has multi solution\n";
            else
                cout << "No solution\n";
            break;
        }
        else
            cerr << "Invalid input. Please try again\n";
    }
    return 0;
}
