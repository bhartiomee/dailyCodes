#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n;
  vector<int> a;
  vector<int> b;
  int data;
  for (int i = 0; i < n; i++)
  {
    cin >> data;
    a.push_back(data);
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> data;
    b.push_back(data);
  }
  int pa = 0;
  int pm = 0;

  int shift = 0;
  int flag ;
  if(a[pa]<b[pm])flag=1;
  else flag=0;
   // a->1 m->0
  while (pa < n && pm < m)
  {
    if (a[pa] < b[pm] && flag == 1)
      pa++;
    else if (b[pm] < a[pa] && flag == 0)
      pm++;
    else
      {
        shift++;
        flag=(flag==0)?1:0;
      }
  }
  cout << shift+1;
  return 0;
}