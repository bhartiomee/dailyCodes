#include <bits/stdc++.h>
using namespace std;

void generateAnagram(string s, int l, int r, unordered_set<string> &pAna);
vector<int> findAnagrams(string s, string p)
{
  vector<int> sChar(26, 0), pChar(26, 0), ans;
  int n = s.length();
  int len = p.length();
  if (n > len)
    return ans;

  for (int i = 0; i < len; i++)
  {
    sChar[s[i] - 'a']++;
    pChar[p[i] - 'a']++;
  }
  if (sChar == pChar)
    ans.push_back(0);

  for (int i = len; i < n; i++)
  {
    sChar[s[i] - 'a']++;
    sChar[s[i - len] - 'a']--;
    if (sChar == pChar)
      ans.push_back(i - len + 1);
  }
  return ans;
}

void generateAnagram(string s, int l, int r, unordered_set<string> &pAna)
{
  if (l == r)
    pAna.insert(s);
  else
  {
    for (int i = l; i <= r; i++)
    {
      swap(s[i], s[l]);
      generateAnagram(s, l + 1, r, pAna);
      swap(s[i], s[l]);
    }
  }
}
int main()
{
  string s, p;
  s = "cbaebabacd";
  p = "abc";

  findAnagrams(s, p);
}