#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int cycle = 1;
  int i = cycle;
  int total = 0;
  int sum = 0;
  int cnt=0;
  while (cnt < n)
  {
    if (cnt>0 && (cnt)%8 == 0)
    {
      total+=sum;
      cout<<cycle<<endl;
      cycle++;
      i=cycle;
      sum=0;
    }
    cnt++;
      sum+=i;
      cout<<i<<" ";
      i++;
    
  }
  cout<<total;
  return 0;
}