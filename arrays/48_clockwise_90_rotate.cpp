void rotate(vector<vector<int>> &matrix)
{
  int n = matrix.size();

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++) //i+1 here beacuse swap(m[i][j],m[j][i]) for(10,01) 
    // but again when we come t0 01 we will again swap them so we get originl matrix so swap on the line of diagonal
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}
