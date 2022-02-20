/*
Brute Force can be : lets say we have d=1 so lets start doing  a[i]/j ,till we dont get sum==0 because
say if j=3 gives sum=0 so j=4 will also give 0 becuse bigger elemet less remainder. 
so here we notice a monotonocity , so we can think in direction of binary search.
low=1 and high can be max of all element.

*/
class Solution
{
public:
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    sort(nums.begin(), nums.end());
    int low = 1;
    int high = INT_MIN;
    for (auto n : nums)
      high = max(n, high);
    return bs(nums, threshold, low, high);
  }
  int bs(vector<int> &nums, int threshold, int low, int high)
  {
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (isSumLess(nums, mid, threshold))
      {
        if (!isSumLess(nums, mid - 1, threshold))
          return mid;
        else
          high = mid - 1;
      }
      else
        low = mid + 1;
    }
    return high;
  }

  bool isSumLess(vector<int> &nums, int mid, int threshold)
  {
    double sum = 0;
    double m = mid * 1.0;
    for (auto n : nums)
    {
      sum += ceil(n / m);
    }
    return (sum <= threshold);
  }
};