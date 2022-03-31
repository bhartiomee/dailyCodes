#include <bits/stdc++.h>
using namespace std;

void createDict(vector<vector<char>> &digiMap);
void solve(string tmp, int idx, string digits, vector<vector<char>> &digiMap);
vector<string> ans;
vector<string> letterCombinations(string digits)
{
  vector<vector<char>> digiMap;
  createDict(digiMap);
  string tmp;
  solve(tmp, 0, digits, digiMap);

  return ans;
}
void solve(string tmp, int idx, string digits, vector<vector<char>> &digiMap)
{
  if (idx == digits.size())
  {
    ans.push_back(tmp);
    return;
  }

  for (int i = 0; i < digiMap[digits[idx] - 2].size(); i++)
  {
    tmp[i] = digiMap[digits[idx] - 2][idx];
    solve(tmp, idx + 1, digits, digiMap);
  }
}

void createDict(vector<vector<char>> &digiMap)
{
  digiMap[0] = {'a', 'b', 'c'};
  digiMap[1] = {'d', 'e', 'f'};
  digiMap[2] = {'g', 'h', 'i'};
  digiMap[3] = {'j', 'k', 'l'};
  digiMap[4] = {'m', 'n', 'o'};
  digiMap[5] = {'p', 'q', 'r', 's'};
  digiMap[6] = {'t', 'u', 'v'};
  digiMap[7] = {'w', 'x', 'y', 'z'};
}
int main()
{
  string digits = "23";
  letterCombinations(digits);
}
