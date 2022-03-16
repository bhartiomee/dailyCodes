#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums)
{
  int currminStep = 0;
  int currmaxStep = 0;
  int level = 1;
  int n = nums.size();
  if (n == 1)
    return 0;
  while (currminStep <= currmaxStep)
  {
    int nextMaxStep = 0;

    for (int i = currminStep; i <= currmaxStep; i++)
    {
      nextMaxStep = max(nextMaxStep, i + nums[i]);
      if (nextMaxStep >= n - 1)
        return level;
    }

    currminStep = currmaxStep + 1;
    currmaxStep = nextMaxStep;
    level++;
  }
  return -1;
}

int main()
{
  vector<int> nums = {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5};
  cout << jump(nums);
  return 1;
}