unordered_map<int, Node *> vis;
Node *cloneGraph(Node *node)
{
  if (!node)
  {
    return NULL;
  }
  Node *root = new Node(node->val);
  vector<Node *> adj;
  Node *curr = node;
  if (vis.find(root->val) == vis.end())
    dfs(curr, root);

  return root;
}
void dfs(Node *curr, Node *root)
{
  vis[root->val] = root;
  for (auto n : curr->neighbors)
  {
    if (vis.find(n->val) == vis.end())
    {
      Node *tmp = new Node(n->val);
      root->neighbors.push_back(tmp);
      dfs(n, tmp);
    }
    else
    {
      root->neighbors.push_back(vis[n->val]);
    }
  }
}