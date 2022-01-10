//https://leetcode.com/problems/shuffle-string/submissions/
#include <bits/stdc++.h>
using namespace std;
string restoreString(string s, vector<int> &indices);
int main()
{
  string s;
  cin >> s;
  vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
  cout << restoreString(s, indices);
}
string restoreString(string s, vector<int> &indices)
{
  int n = s.length();

  for (int i = 0; i < n; i++)
  {
    while (indices[i] != i)
    {
      swap(s[i], s[indices[i]]);             //now that the chars are shuffled
      swap(indices[i], indices[indices[i]]); //shuffle the indices too
    }
  }

  return s;
}