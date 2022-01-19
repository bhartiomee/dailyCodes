// https://leetcode.com/problems/count-the-number-of-consistent-strings/submissions/
int countConsistentStrings(string allowed, vector<string> &words)
{
  unordered_set<char> st;
  for (int i = 0; i < allowed.length(); i++)
  {
    st.insert(allowed[i]);
  }
  int cnt = words.size();

  for (int i = 0; i < words.size(); i++)
  {
    bool rep = false;
    for (int j = 0; j < words[i].length(); j++)
    {
      if (st.find(words[i][j]) == st.end())
      {
        cnt--;
        break;
      }
    }
  }
  return cnt;
}
