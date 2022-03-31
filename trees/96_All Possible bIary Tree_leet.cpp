#include <bits/stdc++.h>
using namespace std;
//tree structure
struct TreeNode
{
  TreeNode *left;
  TreeNode *right;
  int data;

  TreeNode(int data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

// count
int numTrees(int n)
{
  int numTrees(int n)
  {
    long long int catalan[n + 1];
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; i++)
    {
      catalan[i] = 0;
      for (int j = 0; j < i; j++)
      {
        catalan[i] += catalan[j] * catalan[i - 1 - j];
      }
    }
    return catalan[n];
  }
}

// print
unordered_map<int, vector<TreeNode *>> mp;

vector<TreeNode *> allPossibleFBT(int n)
{
  if (mp.find(n) == mp.end())
  {
    vector<TreeNode *> nodes;
    if (n == 1)
    {
      nodes.push_back(new TreeNode());
    }
    else if (n % 2 == 1)
    {
      for (int i = 0; i < n; i++)
      {
        vector<TreeNode *> left = allPossibleFBT(i);
        vector<TreeNode *> right = allPossibleFBT(n - i - 1);

        for (auto l : left)
        {
          for (auto r : right)
          {
            TreeNode *root = new TreeNode(0, l, r);
            nodes.push_back(root);
          }
        }
      }
    }
    mp[n] = nodes;
  }
  return mp[n];
}
int main()
{
  int n;
  cin >> n;
  // cout << numTrees(n);
  allPossibleFBT(n);
}
