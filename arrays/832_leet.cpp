vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{
  int m = image.size();
  int n = image[0].size();

  int j;
  for (int i = 0; i < m; i++)
  {
    for (j = 0; j < n / 2; j++)
    {
      int tmp = image[i][j];
      image[i][j] = image[i][n - j - 1];
      image[i][n - j - 1] = tmp;
      image[i][j] = (image[i][j] == 0) ? 1 : 0;
      image[i][n - j - 1] = (image[i][n - j - 1] == 0) ? 1 : 0;
    }
    if (n % 2 == 1)
      image[i][j] = (image[i][j] == 0) ? 1 : 0;
  }
  return image;
}