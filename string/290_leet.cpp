#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
  stringstream ss(s);  //to split the string
  vector<string> str; 
  string word;

  while (ss >> word) //as we use cin>>variable
  {
    str.push_back(word);
  }

  if (str.size() != pattern.length())
    return false;

  unordered_map<char, string> m;
  set<string> st;
  for (int i = 0; i < pattern.size(); i++)
  {
    if (m.find(pattern[i]) != m.end())
    {
      if (m[pattern[i]] != str[i])
      {
        return false;
      }
    }
    else
    {
      if (st.count(str[i]) > 0)
      {
        return false;
      }
      m[pattern[i]] = str[i];
      st.insert(str[i]);
    }
  }
  return true;
}
int main()
{
  string pattern, s;
  cin >> pattern >> s;
  cout << wordPattern(pattern, s);
  return 0;
}
