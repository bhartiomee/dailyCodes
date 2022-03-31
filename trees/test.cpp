#include <bits/stdc++.h>
using namespace std;

struct node
{
  float performance;
  node *left;
  node *right;
};
float ans = 0.0;
float func(node *ceo)
{

  if (!ceo)
    return 0.0;
  solve(ceo, 0, 1);
  return ans;
}

pair<float, int> solve(node *root, float sum, int noOfChildern)
{
  if (!root)
    return {0.0, 0};
  if (!root->left && !root->right)
    return {root->performance, 1};

  pair<float, int> lst = solve(root->left, sum + root->performance, noOfChildern + 1);
  pair<float, int> rst = solve(root->right, sum + root->performance, noOfChildern + 1);

  float sum = lst.first + rst.first+root->performance;
  int children = lst.second + rst.second+1;
  float avg = (sum / children);
  ans = max(ans, avg);
  return {sum, children};
}