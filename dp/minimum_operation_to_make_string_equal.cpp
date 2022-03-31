#include <bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2);
int main()
{
  string w1 = "leetcode";
  string w2 = "etco";
  minDistance(w1, w2);
}
int minDistance(string word1, string word2)
{
  unordered_map<char, int> w1, w2;

  for (auto w : word1)
  {
    w1[w]++;
  }
  for (auto w : word2)
  {
    w2[w]++;
  }

  int insertion = 0;
  int del = 0;

  for (auto w : word1)
  {
    if (w2.find(w) != w2.end())
    {
      del += abs(w1[w] - w2[w]);
    }
    else
    {
      del += w1[w];
    }
  }
  for (auto w : word2)
  {
    if (w1.find(w) == w1.end())
    {
      insertion += w2[w];
    }
  }
  return insertion + del;
}
