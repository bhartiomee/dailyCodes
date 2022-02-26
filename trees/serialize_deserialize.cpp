class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (!root)
      return "";
    string coded = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      auto tmp = q.front();
      q.pop();
      if (tmp != NULL)
      {
        coded.append(to_string(tmp->val));
        q.push(tmp->left);
        q.push(tmp->right);
      }
      else
      {
        coded.append("#");
      }
      coded.append(",");
      // cout<<coded<<endl;
    }
    // cout<<coded;
    return coded;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string str)
  {
    if (str.length() == 0)
      return NULL;
    stringstream s(str);
    string data;
    getline(s, data, ',');
    queue<TreeNode *> q;
    // cout<<data<<endl;
    TreeNode *node = new TreeNode(stoi(data));
    q.push(node);

    while (!q.empty())
    {
      auto tmp = q.front();
      q.pop();
      getline(s, data, ',');
      if (data != "#")
      {
        TreeNode *lst = new TreeNode(stoi(data));
        tmp->left = lst;
        q.push(lst);
      }
      else
      {
        tmp->left = NULL;
      }
      getline(s, data, ',');
      if (data != "#")
      {
        TreeNode *rst = new TreeNode(stoi(data));
        tmp->right = rst;
        q.push(rst);
      }
      else
      {
        tmp->right = NULL;
      }
    }
    return node;
  }
};