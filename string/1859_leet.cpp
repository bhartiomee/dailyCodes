#include <bits/stdc++.h>
using namespace std;

string sortSentence(string s)
{
  int n = s.length();
  vector<string> str(n);
  int idx;
  string word = "";
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] >= 48 && s[i] <= 57)
    {
      int idx = s[i] - '0';
      str[idx] = word;
      cnt++;
      word = "";
    }
    else if (s[i] != ' ')
      word += s[i];
  }
  string ans = "";
  for (int i = 1; i <= cnt; i++)
  {
    ans += str[i] + " ";
  }
  if (ans[ans.length() - 1] == ' ')
    ans = ans.substr(0, ans.length() - 1);
  return ans;
}

int main()
{
  string s = "is2 sentence4 This1 a3";
  cout << sortSentence(s);
  return 0;
}