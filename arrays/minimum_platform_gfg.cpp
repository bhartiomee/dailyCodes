
// merge interval based
int findPlatform(int arr[], int dep[], int n)
{
  // Your code here
  sort(arr, arr + n);
  sort(dep, dep + n);

  int i = 1;
  int j = 0;
  int cnt = 1;

  while (i < n && j < n)
  {
    if (arr[i] > dep[j])
    {
      j++;
    }
    else
      cnt++;

    i++;
  }
  return cnt;
}
