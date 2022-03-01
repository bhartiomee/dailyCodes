// time: O(n*no of bits)
vector<int> countBits(int n)
{
  vector<int> ans;
  ans.push_back(0);
  for (int i = 1; i <= n; i++)
  {
    int noOfSetBits = findSetBits(i);
    ans.push_back(noOfSetBits);
  }
  return ans;
}

int findSetBits(int num)
{
  int cnt = 0;
  while (num)
  {
    if (num & 1)
      cnt++;
    num = (num >> 1);
  }
  return cnt;
}

/*
There is one imporant observation we can make about the number of bits in each number.

Each Power of 2 has exactly only 1 bit. (2 : 0010 , 4: 0100, 8:1000, 16:10000)
Each number after the power of 2 follows a pecular pattern :
0 → 0
1 → 0
2 → 1 + dp[0] Nearest Power of 2
3 → 1 + dp[1] 1 greater than nearest
4 → 1 + dp[0] Nearest
5 → 1+ dp[1] 1 greater than nearest
6 → 1+ dp[2] 2 greater than nearest
7 → 1+ dp[3] 3 greater than nearest
8 → 1+ dp[0] Nearest
9 → 1+ dp[1]
10 → 1+ dp[2]
11 → 1+ dp[3]
12 → 1+ dp[4]
 O(n), one pass
*/
vector<int> countBits(int n)
{
  vector<int> ans(n + 1, 0);
  ans[0] = 0;
  if (n >= 1)
    ans[1] = 1;
  int nearestPower = 2;
  int curr = 2;
  while (curr <= n)
  {
    nearestPower = isPowerOf2(curr) ? curr : nearestPower;
    ans[curr] = 1 + ans[curr - nearestPower];
    curr++;
  }
  return ans;
}

bool isPowerOf2(int x)
{
  return x && (!(x & (x - 1)));
}
