#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string> &words)
{
  unordered_set<char> st;
  for (int i = 0; i < allowed.length(); i++)
  {
    st.insert(allowed[i]);
  }
  int cnt = 0;

  for (int i = 0; i < words.size(); i++)
  {
    bool rep = false;
    for (int j = 0; j < words[i].length(); j++)
    {
      if (st.find(words[i][j]) == st.end())
      {
        rep = true;
        break;
      }
    }
    if (!rep)
      cnt++;
  }
  return cnt;
}

int main()
{
  vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
  string allowed;
  cin >> allowed;
  cout << countConsistentStrings(allowed, words);
  return 1;
}
