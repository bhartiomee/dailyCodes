#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<char>> &board, int i, int j);
bool isValid(int num, vector<vector<char>> &board, int r, int c);

void solveSudoku(vector<vector<char>> &board)
{
  bool h = solve(board, 0, 0);
}
bool solve(vector<vector<char>> &board, int i, int j)
{
  if (i == 8 && j == 9)
    return true;
  if (j == 9)
  {
    i++;
    j = 0;
  }

  if (board[i][j] != '.')
    return solve(board, i, j + 1);

  for (char num = '1'; num <= '9'; num++)
  {
    if (isValid(num, board, i, j))
    {
      board[i][j] = num;
      if (solve(board, i, j + 1))
        return true;
    }
    board[i][j] = '.';
  }
  return false;
}

bool isValid(char num, vector<vector<char>> &board, int r, int c)
{

  for (int j = 0; j < 9; j++)
  {
    if (board[r][j] == num)
      return false;
  }

  for (int i = 0; i < 9; i++)
  {
    if (board[i][c] == num)
      return false;
  }
  int startRow = r - r % 3,
      startCol = c - c % 3;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[i + startRow][j +
                              startCol] == num)
        return false;
  return true;
}

int main()
{
  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  solveSudoku(board);
}