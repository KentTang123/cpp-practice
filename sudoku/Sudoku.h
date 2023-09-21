#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sudoku
{
public:
    Sudoku();
    Sudoku(string Probfile);
    Sudoku(string Samplefile, string Probfile);
    void SetSampleBoard(string Samplefile);
    void SetProblemBoard(string Probfile);
    int **GetSampleBoard();
    int **GetProblemBoard();
    int **GetTransformBoard();
    int **GetOutputBoard();
    int **GetSolvedBoard();
    void PrintBoard(int **Board);
    bool CheckBoard(int **Board);
    void Transform();
    void Generate();
    bool Solve(int **Board);
    bool CheckUniqueness();

private:
    int **SampleBoard;
    int **TransformBoard;
    int **OutputBoard;
    int **ProblemBoard;
    int **SolvedBoard;
    int **AnotherSolvedBoard;
    fstream file;
    size_t size;
    bool Check(vector<int> Input, size_t size);
    bool RowcolCheck(int **Board, int row, int col, int num);
    bool Blockcheck(int **Board, int row, int col, int num);
    bool AnotherSol();
};

#endif