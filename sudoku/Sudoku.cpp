#include "Sudoku.h"

Sudoku::Sudoku()
{
    SetSampleBoard("sudoku.txt");
    SetProblemBoard("problem.txt");
}

Sudoku::Sudoku(string Probfile)
{
    SetProblemBoard(Probfile);
}

Sudoku::Sudoku(string Samplefile, string Probfile)
{
    SetSampleBoard(Samplefile);
    SetProblemBoard(Probfile);
}

void Sudoku::SetSampleBoard(string Samplefile)
{
    size = 9;

    // initialize SampleBoard
    SampleBoard = new int *[size];
    for (int i = 0; i < size; i++)
        SampleBoard[i] = new int[size];

    // initialize TransformBoard
    TransformBoard = new int *[size];
    for (int i = 0; i < size; i++)
        TransformBoard[i] = new int[size];

    file.open(Samplefile, ios::in);

    if (!file)
        cerr << "Can't open file!\n";

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
        {
            file >> SampleBoard[row][col];
            TransformBoard[row][col] = SampleBoard[row][col];
        }
    file.close();
}

void Sudoku::SetProblemBoard(string Probfile)
{
    ProblemBoard = new int *[size];
    for (int i = 0; i < size; i++)
        ProblemBoard[i] = new int[size];

    SolvedBoard = new int *[size];
    for (int i = 0; i < size; i++)
        SolvedBoard[i] = new int[size];

    // initialize ProblemBoard
    file.open(Probfile, ios::in);

    if (!file)
        cerr << "Can't open file!\n";

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
        {
            file >> ProblemBoard[row][col];
            SolvedBoard[row][col] = ProblemBoard[row][col];
        }
    file.close();
}

int **Sudoku::GetSampleBoard()
{
    return SampleBoard;
}

int **Sudoku::GetProblemBoard()
{
    return ProblemBoard;
}

int **Sudoku::GetTransformBoard()
{
    return TransformBoard;
}

int **Sudoku::GetOutputBoard()
{
    return OutputBoard;
}

int **Sudoku::GetSolvedBoard()
{
    return SolvedBoard;
}

void Sudoku::PrintBoard(int **Board)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            cout << left << setw(4) << Board[row][col];
        }
        cout << endl;
    }
}

bool Sudoku::Check(vector<int> Input, size_t size)
{
    vector<int> CheckArr;

    for (int i = 0; i < size; i++)
        CheckArr.push_back(Input[i]);

    sort(CheckArr.begin(), CheckArr.end());

    for (int i = 0; i < size; i++)
        if (CheckArr.at(i) != (i + 1))
            return false;

    return true;
}

bool Sudoku::CheckBoard(int **Board)
{
    vector<int> check_line;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            check_line.push_back(Board[row][col]);
        }
        if (!Check(check_line, size))
            return false;

        check_line.clear();
    }

    for (int col = 0; col < size; col++)
    {
        for (int row = 0; row < size; row++)
        {
            check_line.push_back(Board[row][col]);
        }
        if (!Check(check_line, size))
            return false;

        check_line.clear();
    }

    vector<vector<int>> check_block(size);

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            if (((row / 3) == 0) && ((col / 3) == 0))
                check_block[0].push_back(Board[row][col]);

            else if (((row / 3) == 0) && ((col / 3) == 1))
                check_block[1].push_back(Board[row][col]);

            else if (((row / 3) == 0) && ((col / 3) == 2))
                check_block[2].push_back(Board[row][col]);

            else if (((row / 3) == 1) && ((col / 3) == 0))
                check_block[3].push_back(Board[row][col]);

            else if (((row / 3) == 1) && ((col / 3) == 1))
                check_block[4].push_back(Board[row][col]);

            else if (((row / 3) == 1) && ((col / 3) == 2))
                check_block[5].push_back(Board[row][col]);

            else if (((row / 3) == 2) && ((col / 3) == 0))
                check_block[6].push_back(Board[row][col]);

            else if (((row / 3) == 2) && ((col / 3) == 1))
                check_block[7].push_back(Board[row][col]);

            else if (((row / 3) == 2) && ((col / 3) == 2))
                check_block[8].push_back(Board[row][col]);

    for (int i = 0; i < size; i++)
        if (!Check(check_block[i], size))
            return false;

    return true;
}

void Sudoku::Transform()
{
    int **middle;
    middle = new int *[size];
    for (int i = 0; i < size; i++)
        middle[i] = new int[size];

    int mode;
    cout << "Mode 0 to end the transformation\nMode 1 to switch 2 numbers\nMode 2 to Switch 2 rows\nMode 3 to switch 2 columns\nMode 4 to rotate 90 degree right\n";

    while (cin >> mode)
    {
        if (mode == 0) // exit
            break;
        else if (mode == 1) // Switch number
        {
            int num1, num2;
            cout << "Please enter 2 numbers you want to switch\n";
            cin >> num1 >> num2;

            for (int row = 0; row < size; row++)
                for (int col = 0; col < size; col++)
                    if (TransformBoard[row][col] == num1)
                        TransformBoard[row][col] = num2;
                    else if (TransformBoard[row][col] == num2)
                        TransformBoard[row][col] = num1;

            cout << "Please select your next move\n";
        }

        else if (mode == 2) // Switch row
        {
            cout << "Please enter 2 rows(3row as a unit) you want to switch (0,1,2)\n";
            int row1, row2, x;
            cin >> row1 >> row2;

            x = row1;
            row1 = (row1 < row2) ? x : row2;
            row2 = (row1 < row2) ? row2 : x;

            for (int row = 0; row < size; row++)
                for (int col = 0; col < size; col++)
                    middle[row][col] = TransformBoard[row][col];

            for (int row = 0; row < size; row++)
                for (int col = 0; col < size; col++)
                    if (row / 3 == row1)
                        TransformBoard[row][col] = middle[row + (abs(row1 - row2)) * 3][col];

                    else if (row / 3 == row2)
                        TransformBoard[row][col] = middle[row - (abs(row1 - row2)) * 3][col];

            cout << "Please select your next move\n";
        }

        else if (mode == 3) // Switch col
        {
            cout << "Please enter 2 columns(3col as a unit) you want to switch (0,1,2)\n";
            int col1, col2, x;
            cin >> col1 >> col2;

            x = col1;
            col1 = (col1 < col2) ? x : col2;
            col2 = (col1 < col2) ? col2 : x;

            for (int row = 0; row < size; row++)
                for (int col = 0; col < size; col++)
                    middle[row][col] = TransformBoard[row][col];

            for (int row = 0; row < size; row++)
                for (int col = 0; col < size; col++)
                    if (col / 3 == col1)
                        TransformBoard[row][col] = middle[row][col + (abs(col1 - col2)) * 3];

                    else if (col / 3 == col2)
                        TransformBoard[row][col] = middle[row][col - (abs(col1 - col2)) * 3];

            cout << "Please select your next move\n";
        }

        else if (mode == 4) // Rotate 90 degree right
        {
            int time;
            cout << "Please enter how many time you want to rotate the board\n";
            cin >> time;

            for (int i = 0; i < (time % 4); i++)
            {
                for (int row = 0; row < size; row++)
                    for (int col = 0; col < size; col++)
                        middle[row][col] = TransformBoard[row][col];

                for (int row = 0; row < size; row++)
                    for (int col = 0; col < size; col++)
                        TransformBoard[row][col] = middle[size - 1 - col][row];
            }
            cout << "Please select your next move\n";
        }
    }
}

void Sudoku::Generate()
{  
    OutputBoard = new int *[size];
    for (int i = 0; i < size; i++)
        OutputBoard[i] = new int[size];

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
        {
            OutputBoard[row][col] = TransformBoard[row][col];
            
        }
    
    int counter=0;
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {   
            int x=OutputBoard[r][c];
            OutputBoard[r][c]=0;

            cout<<r<<" , "<<c<<endl;
            for (int row = 0; row < size; row++)
            {
                for (int col = 0; col < size; col++)
                {
                    ProblemBoard[row][col]=OutputBoard[row][col];
                    SolvedBoard[row][col]=ProblemBoard[row][col];
                }    
     
            }
            Solve(SolvedBoard);
            if(!(CheckUniqueness()))
            {
                OutputBoard[r][c]=x;
                counter++;
            }

            if(counter>=20)
                return;
        }
    }    
}

bool Sudoku::Solve(int **Board)
{
    if (CheckBoard(Board))
        return true;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (Board[row][col] == 0)
            {
                for (int i = 1; i < 10; i++)
                {
                    if ((RowcolCheck(Board, row, col, i)) && Blockcheck(Board, row, col, i))
                    {
                        Board[row][col] = i;
                        if (Solve(Board))
                            return true;
                        else
                            Board[row][col] = 0;
                    }
                }
                if (Board[row][col] == 0)
                    return false;
            }
        }
    }
    return false;
}

bool Sudoku::CheckUniqueness()
{
    AnotherSolvedBoard = new int *[size];
    for (int i = 0; i < size; i++)
        AnotherSolvedBoard[i] = new int[size];

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            AnotherSolvedBoard[row][col] = ProblemBoard[row][col];

    if (AnotherSol())
    {
        for (int row = 0; row < size; row++)
            for (int col = 0; col < size; col++)
                if (AnotherSolvedBoard[row][col] != SolvedBoard[row][col])
                    return false;

        return true;
    }
    return false;
}

bool Sudoku::RowcolCheck(int **Board, int row, int col, int num)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if ((i == row || j == col) && Board[i][j] == num)
                return false;

    return true;
}

bool Sudoku::Blockcheck(int **Board, int row, int col, int num)
{
    vector<int> check_block;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i / 3 == row / 3 && j / 3 == col / 3 && i != row && j != col)
                check_block.push_back(Board[i][j]);

    for (int i = 0; i < check_block.size(); i++)
        if (check_block.at(i) == num)
            return false;

    return true;
}

bool Sudoku::AnotherSol()
{
    if (CheckBoard(AnotherSolvedBoard))
        return true;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (AnotherSolvedBoard[row][col] == 0)
            {
                for (int i = 9; i > 0; i--)
                {
                    if ((RowcolCheck(AnotherSolvedBoard, row, col, i)) && Blockcheck(AnotherSolvedBoard, row, col, i))
                    {
                        AnotherSolvedBoard[row][col] = i;
                        if (AnotherSol())
                            return true;
                        else
                            AnotherSolvedBoard[row][col] = 0;
                    }
                }
                if (AnotherSolvedBoard[row][col] == 0)
                    return false;
            }
        }
    }
    return false;
}
