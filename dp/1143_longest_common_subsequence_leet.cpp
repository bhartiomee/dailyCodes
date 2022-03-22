// recursion
int longestCommonSubsequence(string text1, string text2)
{

  return solve(text1, text2, 0, 0);
}

int solve(string s1, string s2, int i, int j)
{
  if (i == s1.length() || j == s2.length())
    return 0;
  if (s1[i] == s2[j])
  {
    return 1 + solve(s1, s2, i + 1, j + 1); // if matched add and increase both pointer
  }

  else
    return max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
  // if not matched, increase one pointer at a time, Eg: abcde , bcde
}

// rec+memo
int memo[1001][1001];
int longestCommonSubsequence(string text1, string text2)
{
  memset(memo, -1, sizeof(memo));
  return solve(text1, text2, 0, 0);
}

int solve(string &s1, string &s2, int i, int j)
{
  if (i == s1.length() || j == s2.length())
    return 0;

  if (memo[i][j] != -1)
    return memo[i][j];

  if (s1[i] == s2[j])
  {
    return memo[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
  }

  else
    return memo[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
}

