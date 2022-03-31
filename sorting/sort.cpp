// selection sort
vector<int> sortArray(vector<int> &nums)
{
  int n = nums.size();

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (nums[i] > nums[j])
      {
        swap(nums[i], nums[j]);
      }
    }
  }
  return nums;
}

// merge sort
vector<int> sortArray(vector<int> &nums)
{
  divide(nums, 0, nums.size() - 1);
  return nums;
}

void divide(vector<int> &nums, int i, int j)
{
  if (i >= j)
    return;

  int m = (i + j) / 2;
  divide(nums, i, m);
  divide(nums, m + 1, j);
  conquer(nums, i, m, m + 1, j);
}

void conquer(vector<int> &nums, int s1, int e1, int s2, int e2)
{
  int tmp[e2 - s1 + 1];
  int c = 0;
  int i = s1;
  int j = s2;

  while (i <= e1 && j <= e2)
  {
    tmp[c++] = (nums[i] < nums[j]) ? nums[i++] : nums[j++];
  }
  while (i <= e1)
  {
    tmp[c++] = nums[i];
    i++;
  }
  while (j <= e2)
  {
    tmp[c++] = nums[j];
    j++;
  }

  for (int k = 0; k < e2 - s1 + 1; k++)
  {
    nums[s1 + k] = tmp[k];
  }
}
