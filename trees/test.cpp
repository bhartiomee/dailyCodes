#include <iostream>
using namespace std;

int main()
{
  // your code goes here
  int t;
  cin >> t;
  while (t--)
  {
    int x, y, z;
    cin >> x >> y >> z;

    int cp = x * y;
    int sp = x * z;
    int profit = sp - cp;
    cout << profit << endl;
  }
  return 0;
}
