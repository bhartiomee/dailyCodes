int maxProductDifference(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  int n = nums.size();
  return ((nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]));
}

//max diff will of a smallest number and a largest number
// and smallest product will of two small number and same for largest numbers
