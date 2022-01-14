// fibonacci
//iterative
int fib(int n)
{
  if (n <= 1)
    return n;
  int f = 0;
  int s = 1;
  n--;
  while (n--)
  {
    int tmp = s;
    s += f;
    f = tmp;
  }
  return s;
}

// recursive
int fib(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
}
