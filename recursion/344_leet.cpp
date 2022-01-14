// https://leetcode.com/problems/reverse-string/submissions/

//iterative

void reverseString(vector<char> &s)
{

  int n = s.size();
  int i = 0;
  while (i < n / 2)
  {
    char tmp = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = tmp;
    i++;
  }
}
//recursive

void reverseString(vector<char> &s)
{
  helper(0, s.size() - 1, s);
}
void helper(int l, int r, vector<char> &s)
{
  if (l > r)
    return;
  swap(s[l++], s[r--]);
  helper(l, r, s);
}
