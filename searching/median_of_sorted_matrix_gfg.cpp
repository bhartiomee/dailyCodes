int median(vector<vector<int>> &matrix, int r, int c)
{
  // code here
  int low = 1;
  int high = 1e9;
  int median = (r * c) / 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int cnt = findSmallerEqual(mid, matrix);
    if (cnt <= median)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
int findSmallerEqual(int num, vector<vector<int>> &matrix)
{
  int cnt = 0;

  for (int i = 0; i < matrix.size(); i++)
  {
    int low = 0;
    int high = matrix[i].size() - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (matrix[i][mid] <= num)
        low = mid + 1;
      else
        high = mid - 1;
    }
    cnt += low;
  }
  return cnt;
}
