//iterative
bool isPowerOfFour(int n)
{

  if (n <= 0)
    return false;
  while (n > 1)
  {
    if (n % 4 != 0)
      return false;
    n /= 4;
  }
  return true;
}
//recursive
bool isPowerOfFour(int n)
{
  if (n <= 0)
    return false;
  if (n == 1)
    return true;
  return n % 4 == 0 && isPowerOfFour(n / 4);
}

// Trailing Zeroes Solution (Bit Manipulation)

bool isPowerOfFour(int n)
{
  if (n <= 0)
  {
    return false;
  }
  if (n == 1)
  {
    return true;
  }

  // Checking whether the number is a power of two or not
  if (n & n - 1)
  {
    return false;
  }

  // if a binary number is a power of 4 then binary number always have even trailing zeroes
  int c = 0; // c  = number of trailing zeroes
  while (!(n & 1))
  {
    c++;
    n = n >> 1;
  }
  if ((c & 1) == 0)
  {
    return true;
  }
  return false;
}
