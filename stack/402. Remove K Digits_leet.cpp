#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k)
{
  int n = num.length();
  if (n == k)
    return "";
  stack<int> stk;
  string ans = "";
  int i = 0;

  while (i < n)
  {
    while (!stk.empty() && k > 0 && num[stk.top()] > num[i])
    {
      stk.pop();
      k--;
    }
    if (stk.empty() && num[i] == '0')
    {
      i++;
    }
    else
    {
      stk.push(i++);
    }
  }
  while (k && !stk.empty())
  {
    k--;
    stk.pop();
  }
  while (!stk.empty())
  {

    ans += num[stk.top()];
    stk.pop();
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main()
{
  string s = "112";
  int k = 1;
  cout << removeKdigits(s, k);
}