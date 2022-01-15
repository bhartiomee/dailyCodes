//  https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
string firstPalindrome(vector<string> &words)
{
  int n = words.size();
  for (int i = 0; i < n; i++)
  {
    if (isPalindrome(words[i]))
    {
      return words[i];
    }
  }
  return "";
}
bool isPalindrome(string s)
{
  int n = s.length();
  int l = 0;
  int r = n - 1;
  while (l <= r)
  {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }
  return true;
}