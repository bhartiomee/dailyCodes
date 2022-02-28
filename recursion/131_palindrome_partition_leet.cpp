class Solution
{
public:
  vector<vector<string>> ans;
  vector<vector<string>> partition(string s)
  {
    vector<string> tmp;
    helper(tmp, 0, s);
    return ans;
  }

  void helper(vector<string> tmp, int idx, string s)
  {
    if (idx == s.length())
    {
      ans.push_back(tmp);
      return;
    }

    for (int i = idx; i < s.length(); ++i)
    {
      if (isPalindrome(idx, i, s))
      {
        tmp.push_back(s.substr(idx, i - idx + 1));
        helper(tmp, i + 1, s);
        tmp.pop_back();
      }
    }
  }

  bool isPalindrome(int start, int end, string s)
  {
    while (start <= end)
    {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
};