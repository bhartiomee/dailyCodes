string getPermutation(int n, int k)
{
  vector<int> arr;
  string ans = "";
  int fact = 1;
  for (int i = 1; i < n; i++)
  {
    fact *= i;
    arr.push_back(i);
  }
  arr.push_back(n);
  k--;

  while (true)
  {
    int idx = k / fact;
    ans += to_string(arr[idx]);
    arr.erase(arr.begin() + idx);

    if (arr.size() == 0)
      break;
    k = k % fact;
    fact /= arr.size();
  }
  return ans;
}
