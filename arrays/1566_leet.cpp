#include <bits/stdc++.h>
using namespace std;

bool containsPattern(vector<int> &arr, int m, int k)
{
  bool containsPattern(vector<int> & arr, int m, int k)
  {

    int cnt = 0;
    for (int i = 0; i < arr.size() - m; i++)
    {
      if (arr[i] != arr[i + m])
        cnt = 0;
      else
        cnt++;
      if (cnt == (k - 1) * m)
        return true;
    }
    return false;
  }
}

int main()
{
  vector<int> arr = {1, 2, 4, 4, 4, 4};
  int m = 2, k = 3;
  cout << containsPattern(arr, m, k);
  return 0;
}