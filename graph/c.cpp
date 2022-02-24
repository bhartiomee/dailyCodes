#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  char key;
  cin >> key;
  int cnt = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == key)
      cnt++;
  }
  cout << cnt;
}