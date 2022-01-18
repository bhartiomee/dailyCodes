#include <bits/stdc++.h>
using namespace std;

//use mulipication from of the formula t avoid division by zero
bool checkStraightLine(vector<vector<int>> &coordinates)
{
  bool checkStraightLine(vector<vector<int>> & coordinates)
  {
    int dx = coordinates[1][0] - coordinates[0][0];
    int dy = coordinates[1][1] - coordinates[0][1];
    int n = coordinates.size();

    for (int i = 2; i < n; i++)
    {
      int x = coordinates[i][0];
      int y = coordinates[i][1];
      if (dx * (y - coordinates[1][1]) != dy * (x - coordinates[1][0]))
        return false;
    }
    return true;
  }
}
int main()
{
  vector<vector<int>> cord = {{0, 0}, {0, 1}, {0, -1}};
  cout << checkStraightLine(cord);
  return 0;
}