cmake_minimum_required(VERSION 3.20.2)

project(SUDOKU VERSION 1.0.0)

add_executable(Sudoku main.cpp Sudoku.cpp)

configure_file(problem.txt problem.txt )

configure_file(sudoku.txt sudoku.txt)

configure_file(TestOutput.txt TestOutput.txt)